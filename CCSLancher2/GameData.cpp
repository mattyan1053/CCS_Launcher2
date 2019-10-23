# include "GameData.hpp"

bool IsURL(const FilePath& path) {
	return path.starts_with(U"http://") || path.starts_with(U"https://");
}

GameData::GameData(const FilePath& gameDir) : m_homeDir(FileSystem::CurrentDirectory() + gameDir) {
	if (!FileSystem::Exists(m_homeDir) || !FileSystem::IsDirectory(m_homeDir)) {
		Print << U"�ǂݍ��݃G���[: Game�f�B���N�g�������݂��܂���B";
	}
}

void GameData::loadGames() {

	// Game�f�B���N�g�����̃Q�[���𑖍�
	for (const FilePath& gameDir : FileSystem::DirectoryContents(m_homeDir)) {

		// �f�B���N�g���Ŗ�����΃X�L�b�v
		if (!FileSystem::IsDirectory(gameDir)) continue;

		// ini�ǂݍ���
		const INIData ini(gameDir + U"info.ini");
		if (ini.isEmpty()) {
			Print << U"�G���[: info.ini�̓ǂݍ��݂Ɏ��s���܂����i" + FileSystem::BaseName(gameDir) + U"���j";
			continue;
		}

		// �Q�[�����ǂݍ���
		Game game;
		game.title = ini[U"Game.title"];
		game.path = gameDir + ini[U"Game.path"];
		game.tools = ini[U"Game.tools"];
		game.kind = ini[U"Game.kind"];
		game.staff = ini[U"Game.staff"];
		
		game.useMouse = ini.get<bool>(U"Game.useMouse");
		game.useKeyboard = ini.get<bool>(U"Game.useKeyboard");
		game.useGamepad = ini.get<bool>(U"Game.useGamepad");

		game.screenshot = Texture(Image(gameDir + ini[U"Game.image"]).squareClipped(), TextureDesc::Mipped);
		
		// game.hasMovie = ini.get<bool>(U"Game.hasMovie");
		
		game.rdmPath = gameDir + ini[U"Game.readmePath"];
		TextReader reader(game.rdmPath);
		game.readme = reader.readAll();

		const FilePath path = ini[U"Game.path"];
		if (IsURL(path)) {
			game.path = path;
			game.isWebApp = true;
		}
		else {
			game.path = gameDir + path;
		}

		m_list << game;
		
	}

}

const Array<Game>& GameData::getList() {
	return m_list;
}