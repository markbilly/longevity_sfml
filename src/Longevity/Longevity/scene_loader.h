#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include <vector>
#include "scene.h"

class SceneLoader {
public:
	SceneLoader();
	~SceneLoader();
	void Load(std::string file_name, Scene& scene);
private:
	const static int kNumberOfSceneAttributes = 2;
	std::vector<int>* SceneLoader::GetTileMapRow(std::string line);
	std::pair<std::string, std::string> GetAttribute(std::string line);
};

#endif