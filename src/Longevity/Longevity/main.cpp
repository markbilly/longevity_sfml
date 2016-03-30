#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
	const int MillisecondsPerUpdate = 16;

	sf::Clock clock;
	Game *game = new Game();
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(200, 200), "Longevity");

	double previous_time = clock.getElapsedTime().asMilliseconds();
	double lag = 0.0;

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();
		}

		double current_time = clock.getElapsedTime().asMilliseconds();
		double elapsed_time = current_time - previous_time;
		previous_time = current_time;
		lag += elapsed_time;

		game->ProcessInput();

		while (lag >= MillisecondsPerUpdate) {
			game->Update();
			lag -= MillisecondsPerUpdate;
		}

		game->Render(window);
	}
}