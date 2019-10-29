# include "Lancher.hpp"
# include "CommonData.hpp"
# include "State.hpp"
# include "Select.hpp"
# include "Summary.hpp"
# include "Global.hpp"

Lancher::Lancher(const FilePath& path) {

	m_manager.get()->loadGames(path);

}

void Lancher::start() {
	
	TextureAsset::Register(U"back", U"resource/back.png");
	TextureAsset::Register(U"left", U"resource/arrow/left.png");
	TextureAsset::Register(U"right", U"resource/arrow/right.png");
	TextureAsset::Register(U"window", U"resource/window.png");
	TextureAsset::Register(U"bar", U"resource/name_bar.png");
	TextureAsset::Register(U"box", U"resource/box.png");

	FontAsset::Register(U"Title", 60, Typeface::Black);

	m_manager.add<Select>(State::Select);
	m_manager.add<Summary>(State::Summary);

	while (System::Update()) {

		if (m_manager.get()->process) {
			if (m_manager.get()->process->isRunning()) {
				Window::Minimize();
			}
			else {
				Window::Restore();
				m_manager.get()->process = none;
			}
		}

		TextureAsset(U"back").resized(windowSize).draw();

		if (!m_manager.update()) {
			break;
		}

	}

}