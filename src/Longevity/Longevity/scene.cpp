#include "scene.h"

Scene::Scene()
{
	tile_map_ = new std::vector<std::vector<int>*>();
	// 20 x 15 map
	for (int row = 0; row < 15; row++) {
		std::vector<int>* new_row = new std::vector<int>();
		for (int col = 0; col < 20; col++) {
			new_row->push_back(1);
		}
		tile_map_->push_back(new_row);
	}
}

Scene::~Scene()
{
}

void Scene::Render()
{
}
