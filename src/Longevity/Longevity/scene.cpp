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
	for (int i = 0; i < entities_.size(); i++) {
		entities_[i]->Render(window);
	}
}

void Scene::Update() {
	// entities
	for (int i = 0; i < entities_.size(); i++) {
		// apply shit gravity
		entities_[i]->SetVelocity(sf::Vector2f(0.0f, 1.0f));

		// apply shit collision
		for (int j = 0; j < entities_.size(); j++) {
			if (entities_[i] != entities_[j] &&
				entities_[i]->IsCollision(entities_[j]->GetBounds())) {
				entities_[i]->SetVelocity(sf::Vector2f(0.0f, 0.0f));
			}
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

	// convert map tiles to entities
	int pos[2] = { 0, 0 };

	for (int row = 0; row < GetTotalMapRows(); row++) {
		for (int col = 0; col < GetTotalMapCols(); col++) {

			if (tile_map_->at(row)->at(col) > 0) {
				// TODO: tile_factory class to build different tile types
				sf::RectangleShape* tile_shape = new sf::RectangleShape();
				tile_shape->setSize(sf::Vector2f(16, 16));
				tile_shape->setPosition(pos[0], pos[1]);
				tile_shape->setFillColor(sf::Color::Yellow);

				sf::Texture tile_texture = *texture_factory_->CreateTexture("test");
				sf::Sprite* tile_sprite = new sf::Sprite(tile_texture);
				Entity* tile = new Entity(tile_shape, tile_sprite, true);

				entities_.push_back(tile);
			}

			pos[0] += 16;
		}
		pos[0] = 0;
		pos[1] += 16;
	}
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

	int height = GetTotalMapRows() * 16;
	int width = GetTotalMapCols() * 16;

	return sf::IntRect(0, 0, width, height);
}

int Scene::GetTotalMapRows() {
	return tile_map_->size();
}

int Scene::GetTotalMapCols() {
	return tile_map_->at(0)->size();
}
