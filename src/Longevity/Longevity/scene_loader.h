#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include <vector>
#include "scene.h"

struct Attribute {
	std::string key;
	std::string value;
};

class SceneLoader {
public:
	SceneLoader();
	~SceneLoader();
	void Load(std::string file_name, Scene& scene);
private:
	std::vector<int>* SceneLoader::GetTileMapRow(std::string line);
	Attribute GetAttribute(std::string line);
};

#endif