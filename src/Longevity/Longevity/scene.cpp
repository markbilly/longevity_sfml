#include "scene.h"

Scene::Scene(TextureFactory* texture_factory)
{
	texture_factory_ = texture_factory;

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
	delete tile_map_;
}

void Scene::Render(sf::RenderWindow* window)
{
	int pos[2] = { 0, 0 };
	for (int row = 0; row < 15; row++) {
		for (int col = 0; col < 20; col++) {
			sf::Texture texture = *texture_factory_->CreateTexture("test");
			sf::Sprite sprite(texture);
			sprite.setPosition(pos[0], pos[1]);
			window->draw(sprite);
			pos[0] += 16;			
		}
		pos[0] = 0;
		pos[1] += 16;
	}
}
