# include "Select.hpp"
# include "State.hpp"
# include "CommonData.hpp"
# include "Frame.hpp"

Select::Select(const InitData& init) : IScene(init),
	m_frame(m_framePos, m_frameSize), m_summary(U"くわしくみる", { 900, 550 }) {
	
	m_rightButton = Rect(m_rightButtonPos, m_buttonSize);
	m_leftButton = Rect(m_leftButtonPos, m_buttonSize);

	Array<Texture> tmp;
	for (int i = 0; i < 5; i++) {
		tmp << getData().games.getList()[getData().nextID(-2 + i)].screenshot;
	}
	m_frame.setTexture(tmp);

}

void Select::update() {


	if (m_rightButton.leftClicked()) {
		m_frame.m_right = true;
		getData().next();
		Array<Texture> tmp;
		for (int i = 0; i < 5; i++) {
			tmp << getData().games.getList()[getData().nextID(-2 + i)].screenshot;
		}
		m_frame.setTexture(tmp);
	}

	if (m_leftButton.leftClicked()) {
		m_frame.m_left = true;
		getData().prev();
		Array<Texture> tmp;
		for (int i = 0; i < 5; i++) {
			tmp << getData().games.getList()[getData().nextID(-2 + i)].screenshot;
		}
		m_frame.setTexture(tmp);
	}

	m_summary.update();

	if (m_summary.leftClicked()) {
		changeScene(State::Summary);
	}

	m_frame.update();
	

}

void Select::draw() const {

	m_frame.draw();

	TextureAsset(U"left").draw(m_leftButtonPos);
	TextureAsset(U"right").draw(m_rightButtonPos);

	TextureAsset(U"window").drawAt(m_windowPos);
	const auto pos = TextureAsset(U"bar").drawAt(m_barPos).pos;

	
	if (m_titleSpace.movedBy(pos.x, pos.y).contains(m_font(getData().games.getList()[getData().selected()].title).regionAt(m_barPos))){
		m_font(getData().games.getList()[getData().selected()].title).drawAt(m_barPos);
	}
	else {
		m_font(getData().games.getList()[getData().selected()].title).draw(m_titleSpace.stretched(-10).movedBy(pos.x + 10, pos.y + 5));
	}

	auto& data = getData().games.getList()[getData().selected()];
	m_infoFont(U"ジャンル\n開発ツール\n開発スタッフ\n\n操作").draw(100, 480);
	m_infoFont(U": " + data.kind).draw(window);
	m_infoFont(U": " + data.tools).draw(window.movedBy(0, 35));
	m_infoFont(U": " + data.staff).draw(window.movedBy(0, 70));
	String items = U"";
	if (data.useMouse) items += U"マウス  ";
	if (data.useKeyboard) items += U"キーボード  ";
	if (data.useGamepad) items += U"ゲームパッド";
	m_infoFont(U": " + items).draw(window.movedBy(0, 140));

	m_summary.draw();

}