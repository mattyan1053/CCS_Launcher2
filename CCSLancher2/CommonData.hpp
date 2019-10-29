# pragma once
# include <Siv3D.hpp>
# include "GameData.hpp"
# include "CreateProcess.hpp"

class CommonData {
private:

	int m_selected = 0;

public:

	GameData games;

	Optional<s3dx::ProcessInfo> process;

	CommonData() {}

	void loadGames(const FilePath& path);

	void next();
	void prev();

	int nextID(int cur) const;
	int prevID(int cur) const;

	int selected() const;

};