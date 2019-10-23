# pragma once
# include <Siv3D.hpp>
# include "GameInfo.hpp"

class GameData {

private:
	// ゲームリスト
	Array<Game> m_list;

	// ゲームのディレクトリがあるディレクトリ
	const FilePath m_homeDir;

public:

	GameData() = delete;

	GameData(const FilePath& gameDir);

	void loadGames();

	const Array<Game>& getList();

};