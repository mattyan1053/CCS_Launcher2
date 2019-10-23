# pragma once
# include <Siv3D.hpp>
# include "GameData.hpp"

class Lancher {

private:
	GameData m_games;

public:

	Lancher() = delete;

	Lancher(const FilePath& path);

	void update();

	void draw() const;


};