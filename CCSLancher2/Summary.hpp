# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"
# include "InlineFrame.hpp"
# include "Button.hpp"

class Summary : public LancherManager::Scene {

private:

	InlineFrame m_frame;

	Point readmePos = { 650, 50 };
	Size readmeSize = { 600, 600 };

	Button m_back;
	Button m_play;

	const Vec2 m_screenshotPos = { 320, 300 };
	const Size m_screenshotSize = { 500, 375 };

public:

	Summary(const InitData& init);

	void update() override;

	void draw() const override;

};