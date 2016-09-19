#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "texture_factory.h"
#include "scene.h"
#include "camera.h"
#include "input_handler.h"

class Game {
public:
	Game();
	~Game();
	sf::RenderWindow* GetWindow();
	void ProcessInput();
	void Update();
	void Render();
	void SetFps(int fps);
private:
	InputHandler* input_handler_;
	Camera* camera_;
	sf::RenderWindow* window_;
	TextureFactory* texture_factory_;
	Scene* scene_;

	int offset_x_;
	int offset_y_;

	int fps_;
	void RenderFpsText();
};

#endif
