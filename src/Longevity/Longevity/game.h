#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "tile.h"

class Game {
public:
	Game();
	~Game();
	sf::RenderWindow* GetWindow();
	void ProcessInput();
	void Update();
	void Render();
private:
	float circle_radius_;
	sf::CircleShape circle_;
	Tile tile_;
	sf::RenderWindow* window_;
	std::vector<sf::Texture*>* textures_;
};

#endif
