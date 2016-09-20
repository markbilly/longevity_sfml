#include "scene.h"

Scene::Scene(TextureFactory* texture_factory) {
	texture_factory_ = texture_factory;
	attributes_ = new std::map<std::string, std::string>();
}

Scene::~Scene() {
	delete tile_map_;
	delete attributes_;
}

void Scene::Render(sf::RenderWindow* window) {
	int total_rows = tile_map_->size();
	int total_cols = tile_map_->at(0)->size();
	int pos[2] = { 0, 0 };

	for (int row = 0; row < total_rows; row++) {
		for (int col = 0; col < total_cols; col++) {
			sf::Texture texture = *texture_factory_->CreateTexture("test");
			sf::Sprite sprite(texture);
			sprite.setPosition((float)pos[0], (float)pos[1]);

			if (tile_map_->at(row)->at(col) > 0) {
				window->draw(sprite);
			}

			pos[0] += 16;
		}
		pos[0] = 0;
		pos[1] += 16;
	}
}

void Scene::Update() {
	// entities
	for (int i = 0; i < entities_.size(); i++) {
		// apply shit gravity
		entities_[i]->SetVelocity(sf::Vector2f(0.0f, 1.0f));

		// apply shit collision	
		int total_rows = tile_map_->size();
		int total_cols = tile_map_->at(0)->size();
		int pos[2] = { 0, 0 };

		for (int row = 0; row < total_rows; row++) {
			for (int col = 0; col < total_cols; col++) {

				if (tile_map_->at(row)->at(col) > 0) {
					if (entities_[i]->IsCollision(sf::FloatRect(pos[0], pos[1], 16, 16))) {
						entities_[i]->SetVelocity(sf::Vector2f(0.0f, 0.0f));
					}
				}

				pos[0] += 16;
			}
			pos[0] = 0;
			pos[1] += 16;
		}

		// update
		entities_[i]->Update();
	}
}

void Scene::AddEntity(Entity* entity) {
	entities_.push_back(entity);
}

std::map<std::string, std::string>* Scene::GetAttributes() {
	return attributes_;
}

void Scene::SetTileMap(std::vector<std::vector<int>*>* tile_map) {
	tile_map_ = tile_map;
}

void Scene::AddAttribute(std::pair<std::string, std::string> key_value_pair) {
	// check for attribute
	std::map<std::string, std::string>::iterator iterator = attributes_->find(key_value_pair.first);
	if (iterator == attributes_->end()) {
		// add if not found
		attributes_->insert(key_value_pair);
	}
}

sf::IntRect Scene::GetSizeInPixels() {
	if (tile_map_ == nullptr) {
		return sf::IntRect(0, 0, 0, 0);
	}

	int height = tile_map_->size() * 16;
	int width = tile_map_->at(0)->size() * 16;

	return sf::IntRect(0, 0, width, height);
}
