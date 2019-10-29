# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"
# include "Frame.hpp"
# include "Button.hpp"

class Select : public LancherManager::Scene {

private:

	const Point m_windowPos = { 640, 350 };
	const Rect window = Rect(270, 480, 650, 50);

	const Point m_framePos = { 640, 230 };
	const Size m_frameSize = { 1280, 720 };

	const Point m_barPos = { 640, 430 };

	Frame m_frame;

	Rect m_rightButton;
	Rect m_leftButton;

	const Point m_rightButtonPos = { 1129, 141 };
	const Point m_leftButtonPos = { 51, 141 };
	const Size m_buttonSize = { 103, 178 };

	const Font m_font = Font(45, Typeface::Black);
	const Rect m_titleSpace = TextureAsset(U"bar").region();

	const Font m_infoFont = Font(25, Typeface::Heavy);

	Button m_summary;

public:

	Select(const InitData& init);

	void update() override;

	void draw() const override;

};