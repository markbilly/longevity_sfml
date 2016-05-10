#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include <vector>

class MapLoader {
public:
	MapLoader();
	~MapLoader();
	std::vector<std::vector<int>*>* Load(std::string file_name);
private:
};

#endif