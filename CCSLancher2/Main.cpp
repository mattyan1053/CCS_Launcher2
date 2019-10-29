# include <Siv3D.hpp> // OpenSiv3D v0.4.0
# include "Lancher.hpp"
# include "Global.hpp"

Size windowSize = { 1280, 720 };
Array<Texture> g_frames;

void Main()
{

	Window::SetTitle(U"CCS Launcher");

	Window::Resize(windowSize);

	for (int i = 0; i <= 20; i++) {

		Texture texture(U"resource/launch_anim/00" + Pad(i, { 2, U'0' }) + U".png");
		g_frames << texture;

	}

	Lancher lancher(U"Game");

	lancher.start();
}
