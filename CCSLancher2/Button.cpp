# include "Button.hpp"

const Size m_size = { 256, 95 };

Button::Button(String str, Point pos, ColorF color) :
	m_str(str), m_rect(pos, m_size), m_pos(pos), m_color(color) {

}

void Button::update() {
	m_leftClicked = m_rect.leftClicked();
	m_mouseOver = m_rect.mouseOver();
}

void Button::draw() const {

	TextureAsset(U"box").draw(m_pos + Vec2(5, 5));
	m_font(m_str).drawAt(m_rect.center(), m_color);
	if (m_mouseOver) {
		RoundRect(m_rect.scaled(0.95, 0.9), 20).draw(Color(50, 50, 50, 100));
	}

}

bool Button::leftClicked() const{
	return m_leftClicked;
}