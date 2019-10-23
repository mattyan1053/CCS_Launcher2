# pragma once
# include <Siv3D.hpp>
# include "GameInfo.hpp"

class GameData {

private:
	// �Q�[�����X�g
	Array<Game> m_list;

	// �Q�[���̃f�B���N�g��������f�B���N�g��
	const FilePath m_homeDir;

public:

	GameData() = delete;

	GameData(const FilePath& gameDir);

	void loadGames();

	const Array<Game>& getList();

};