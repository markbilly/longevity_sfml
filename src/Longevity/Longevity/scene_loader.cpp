#include "scene_loader.h"
#include <fstream>
#include <sstream>
#include <string>

SceneLoader::SceneLoader() {
}

SceneLoader::~SceneLoader() {
}

void SceneLoader::Load(std::string file_name, Scene& scene) {
	std::vector<std::vector<int>*>* map = new std::vector<std::vector<int>*>();

	std::ifstream file;
	file.open(file_name);

	std::string line;
	int line_number = 1;
	while (std::getline(file, line)) {
		if (line_number <= kNumberOfSceneAttributes) {
			scene.AddAttribute(GetAttribute(line));
		}
		else {
			map->push_back(GetTileMapRow(line));
		}
		line_number++;
	}

	scene.SetTileMap(map);
}

std::vector<int>* SceneLoader::GetTileMapRow(std::string line) {
	std::vector<int>* row_of_codes = new std::vector<int>();

	for (size_t i = 0; i < line.length(); i++) {
		std::string code;
		code += line[i];
		int tile_num = std::atoi(code.c_str());
		row_of_codes->push_back(tile_num);
	}

	return row_of_codes;
}

std::pair<std::string, std::string> SceneLoader::GetAttribute(std::string line) {
	std::string attribute_key = "";
	std::string attribute_value = "";
	bool value = false;

	for (std::size_t i = 0; i < line.length(); i++) {
		if (line[i] == ':') {
			value = true;
			continue;
		}

		if (value) {
			attribute_value += line[i];
		}
		else {
			attribute_key += line[i];
		}
	}

	std::pair<std::string, std::string> attribute(attribute_key, attribute_value);
	return attribute;
}
