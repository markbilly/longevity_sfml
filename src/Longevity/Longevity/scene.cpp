#include "scene.h"
#include "map_loader.h"

Scene::Scene(TextureFactory* texture_factory, std::string map_file_name)
{
	texture_factory_ = texture_factory;

	//tile_map_ = new std::vector<std::vector<int>*>();
	//// 20 x 15 map
	//for (int row = 0; row < 15; row++) {
	//	std::vector<int>* new_row = new std::vector<int>();
	//	for (int col = 0; col < 20; col++) {
	//		new_row->push_back(1);
	//	}
	//	tile_map_->push_back(new_row);
	//}

	MapLoader map_loader = MapLoader();
	tile_map_ = map_loader.Load(map_file_name); // TODO: what happens if the file is not found?
}

Scene::~Scene()
{
	delete tile_map_;
}

void Scene::Render(sf::RenderWindow* window)
{
	int total_rows = tile_map_->size();
	int total_cols = tile_map_->at(0)->size();
	int pos[2] = { 0, 0 };

	for (int row = 0; row < total_rows; row++) {
		for (int col = 0; col < total_cols; col++) {
			sf::Texture texture = *texture_factory_->CreateTexture("test");
			sf::Sprite sprite(texture);
			sprite.setPosition(pos[0], pos[1]);

			if (tile_map_->at(row)->at(col) > 0) {
				window->draw(sprite);
			}

			pos[0] += 16;			
		}
		pos[0] = 0;
		pos[1] += 16;
	}
}
