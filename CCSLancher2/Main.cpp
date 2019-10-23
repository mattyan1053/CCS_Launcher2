# include <Siv3D.hpp> // OpenSiv3D v0.4.0
# include "Lancher.hpp";

void Main()
{
	// 背景を水色にする
	Scene::SetBackground(ColorF(0.8, 0.9, 1.0));

	Lancher lancher(U"Game");

	while (System::Update())
	{
		
		lancher.update();
		lancher.draw();
		
	}
}
