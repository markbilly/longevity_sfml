#include "map_loader.h"
#include <fstream>
#include <sstream>
#include <string>

MapLoader::MapLoader()
{
}

MapLoader::~MapLoader()
{
}

std::vector<std::vector<int>*>* MapLoader::Load(std::string file_name)
{
	std::vector<std::vector<int>*>* map = new std::vector<std::vector<int>*>();

	std::ifstream file;
	file.open(file_name);

	std::string line;
	while (std::getline(file, line)) {
		std::vector<int>* row_of_codes = new std::vector<int>();

		for (size_t i = 0; i < line.length(); i++) {
			std::string code;
			code += line[i];
			int tile_num = std::atoi(code.c_str());
			row_of_codes->push_back(tile_num);
		}

		map->push_back(row_of_codes);
	}

	return map;
}
