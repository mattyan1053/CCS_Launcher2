# include "Frame.hpp"
# include "Global.hpp"

Frame::Frame(Point pos, Size size) : m_pos(pos), m_size(size), m_frameCur(0) {
	initializeStateMachine();
	textures.resize(5);
	goToState(FrameState::Idle);
	
}

void Frame::initializeStateMachine() {

	{
		addState(std::make_shared<Idle>(*this));
		addState(std::make_shared<Moving>(*this));
	}

}

void Frame::setTexture(Array<Texture>& t) {
	for (int i = 0; i < 5; i++) {
		textures[i] = t[i];
	}
}

Frame::Idle::Idle(Frame& _main) : stm::State<FrameState>(FrameState::Idle), main(_main){

}

void Frame::Idle::setUp() {
	main.m_right = false;
	main.m_left = false;
}

void Frame::Idle::update() {
	if (main.m_right) {
		main.m_vec = true;
		main.goToState(FrameState::Moving);
	}
	if (main.m_left) {
		main.m_vec = false;
		main.goToState(FrameState::Moving);
	}
}

void Frame::Idle::draw() const {
	g_frames[0].resized(main.m_size).drawAt(main.m_pos);
	{
		Texture& t = main.textures[2];
		t.resized(t.width() * 220 / t.height(), 220).drawAt(main.m_pos + Point(0, 10));
	}
	{
		Texture& t = main.textures[1];
		t.resized(60 , 210).drawAt(main.m_pos + Point(-520, 10));
	}
	{
		Texture& t = main.textures[3];
		t.resized(60, 210).drawAt(main.m_pos + Point(520, 10));
	}

}

Frame::Moving::Moving(Frame& _main) : stm::State<FrameState>(FrameState::Moving), main(_main){

}

void Frame::Moving::setUp() {
	if (main.m_vec) cur = 0;
	else cur = 20;
}

void Frame::Moving::update() {
	if (main.m_vec) cur++;
	else cur--;
	if (cur > 20 || cur <= 0) main.goToState(FrameState::Idle);
}

void Frame::Moving::draw() const {
	g_frames[cur].resized(main.m_size).drawAt(main.m_pos);

	int c = cur;
	
	if (cur < 4) c = 0;
	else if (cur > 15) c = 15;
	else c = cur - 4;
	
	if (main.m_vec) {
		{
			Texture& t = main.textures[1];
			auto tmp = (t.width() * 220 / t.height() - 60) / 15;
			t.resized(t.width() * 220 / t.height() - tmp * c, 220 - 10 / 17.0 * cur).drawAt(main.m_pos + Point(0 - (520 / 15) * c, 10));
		}
		{
			Texture& t = main.textures[2];
			auto tmp = (t.width() * 220 / t.height() - 60) / 15;
			t.resized(60 + tmp * c, 210 + 10 / 17.0 * cur).drawAt(main.m_pos + Point(520 - (520 / 15) * c, 10));
		}
	}
	 if (!main.m_vec){
		 {
			Texture& t = main.textures[2];
			auto tmp = (t.width() * 220 / t.height() - 60) / 15;
			t.resized(t.width() * 220 / t.height() - tmp * c, 210 + 10 / 17.0 * cur).drawAt(main.m_pos + Point(0 - (520 / 15) * c, 10));
		 }
		{
			Texture& t = main.textures[3];
			auto tmp = (t.width() * 220 / t.height() - 60) / 15;
			t.resized(60 + tmp * c, 210 + 10 / 17.0 * cur).drawAt(main.m_pos + Point(520 - (520 / 15) * c, 10));
		}
	}

}