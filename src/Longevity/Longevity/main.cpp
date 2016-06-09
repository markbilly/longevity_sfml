#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
	const int MillisecondsPerUpdate = 16;

	Game game;
	sf::Clock clock;
	sf::RenderWindow* window = game.GetWindow();

	double previous_time = clock.getElapsedTime().asMilliseconds();
	double lag = 0.0;

	while (window->isOpen()) {
		double current_time = clock.getElapsedTime().asMilliseconds();
		double elapsed_time = current_time - previous_time;
		previous_time = current_time;
		lag += elapsed_time;

		game.ProcessInput();

		while (lag >= MillisecondsPerUpdate) {
			game.Update();
			lag -= MillisecondsPerUpdate;
		}

		game.Render();
	}
}