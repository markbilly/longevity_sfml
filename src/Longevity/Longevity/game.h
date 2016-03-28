#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:
	Game();
	~Game();
	void ProcessInput();
	void Update();
	void Render(sf::RenderWindow *window);
private:
	float circle_radius_;
	sf::CircleShape circle_;
};

#endif
