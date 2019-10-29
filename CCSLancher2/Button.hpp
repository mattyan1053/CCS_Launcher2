# pragma once
# include <Siv3D.hpp>

class Button {

private:

	Rect m_rect;
	Point m_pos;

	Color m_color;

	bool m_leftClicked = false;
	bool m_mouseOver = false;

	Font m_font = Font(30, Typeface::Black);

	String m_str;

public:

	Button() = delete;

	Button(String str, Point pos, ColorF color=Palette::Blue);

	void update();

	void draw() const;

	bool leftClicked() const;

};