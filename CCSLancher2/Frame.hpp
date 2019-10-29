# pragma once
# include <Siv3D.hpp>
# include "State.hpp"
# include "StateMachine.hpp"
# include "CommonData.hpp"

enum FrameState {
	Idle,
	Moving
};

class Frame : public stm::StateMachine<FrameState> {
private:

	const Point m_pos;
	const Size m_size;
	int m_frameCur;

	bool m_vec = true;

	Array<Texture> textures;


	// Array<Texture> m_frames;

public:

	int selected;
	
	bool m_right = false;
	bool m_left = false;

	Frame() = delete;

	Frame(Point pos, Size size);

	void initializeStateMachine() override;

	void setTexture(Array<Texture>&  t);

	struct Idle : public stm::State<FrameState> {

		Frame& main;

		Idle(Frame& _main);

		void setUp() override;
		void update() override;
		void draw() const override;

	};

	struct Moving : public stm::State<FrameState> {
		
		int cur;

		Frame& main;

		Moving(Frame& _main);
		
		void setUp() override;
		void update() override;
		void draw() const override;
	};

};