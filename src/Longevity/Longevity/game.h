#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "texture_factory.h"
#include "scene.h"

class Game {
public:
	Game();
	~Game();
	sf::RenderWindow* GetWindow();
	void ProcessInput();
	void Update();
	void Render();
private:
	sf::RenderWindow* window_;
	TextureFactory* texture_factory_;
	Scene* scene_;
};

#endif
