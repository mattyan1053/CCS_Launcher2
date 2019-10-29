# include "Summary.hpp"
# include "State.hpp"
# include "CommonData.hpp"

const FilePath BrowserPath = U"C:\\Windows\\SystemApps\\Microsoft.MicrosoftEdge_8wekyb3d8bbwe\\MicrosoftEdge.exe";

Summary::Summary(const InitData& init) : IScene(init), 
	m_back(U"–ß‚é", {330, 500}), m_play(U"‚ ‚»‚Ô", {50, 500}, Palette::Red) {

	m_frame = InlineFrame(Rect(readmePos, readmeSize));

}

void Summary::update() {


	m_frame.update(getData().games.getList()[getData().selected()].readme.size());
	m_back.update();
	m_play.update();

	if (m_back.leftClicked()) changeScene(State::Select);

	if (m_play.leftClicked()) {
		const auto game = getData().games.getList()[getData().selected()];
		if (game.isWebApp) {
			getData().process = s3dx::System::CreateProcess(U"", U"-- {}"_fmt(game.path));
		}
		else {
			getData().process = s3dx::System::CreateProcess(game.path);
		}
	}

}

void Summary::draw() const {

	const InlineFrameData frameData = m_frame.getFrameData();
	frameData.contentsArea.draw(Palette::White);
	Texture texture = getData().games.getList()[getData().selected()].readme;
	texture(frameData.contentsOffset, Min(frameData.contentsArea.w, texture.width()), Min(frameData.contentsArea.h, texture.height())).draw(frameData.contentsArea.pos);
	m_frame.draw();
	frameData.region.drawFrame(0, 1.5, Palette::Gray);


	const auto game = getData().games.getList()[getData().selected()];
	const double s = Min((double)m_screenshotSize.x / game.screenshot.size().x, (double)m_screenshotSize.y / game.screenshot.size().y);
	game.screenshot.scaled(s).drawAt(m_screenshotPos).drawFrame(10, 0, Palette::Black).drawFrame(11, 0, Palette::White);

	m_back.draw();
	m_play.draw();

}