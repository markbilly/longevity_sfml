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
	sf::View* view_;
	sf::RenderWindow* window_;
	TextureFactory* texture_factory_;
	Scene* scene_;

	int offset_x_;
	int offset_y_;
};

#endif
