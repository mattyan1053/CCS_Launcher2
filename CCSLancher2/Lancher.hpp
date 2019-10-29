# pragma once
# include <Siv3D.hpp>
# include "GameData.hpp"
# include "Scene.hpp"

class Lancher {

private:
	
	LancherManager m_manager;

public:

	Lancher() = delete;

	Lancher(const FilePath& path);

	void start();


};