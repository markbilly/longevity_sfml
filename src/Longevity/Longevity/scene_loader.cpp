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
	while (std::getline(file, line)) {
		if (line[0] == 's') {
			Attribute attribute = GetAttribute(line);
			scene.AddAttribute(attribute.key, attribute.value);
		}
		else {
			map->push_back(GetTileMapRow(line));
		}
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

Attribute SceneLoader::GetAttribute(std::string line) {		
	std::string attribute_key = "";
	std::string attribute_value = "";
	bool value = false;

	for (std::size_t i = 2; i < line.length(); i++) {
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

	Attribute attribute = { attribute_key, attribute_value };
	return attribute;
}
