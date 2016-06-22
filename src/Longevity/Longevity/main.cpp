#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
	const int MillisecondsPerUpdate = 16;

	Game game;
	sf::Clock clock;
	sf::RenderWindow* window = game.GetWindow();

	double start_time = clock.getElapsedTime().asMilliseconds();
	double previous_time = start_time;
	double lag = 0.0;

	int updates_processed = 0;

	while (window->isOpen()) {
		double current_time = clock.getElapsedTime().asMilliseconds();
		double elapsed_time = current_time - previous_time;

		if (current_time - start_time > 1000) {
			game.SetFps(updates_processed);
			updates_processed = 0;
			start_time = clock.getElapsedTime().asMilliseconds();
		}

		previous_time = current_time;
		lag += elapsed_time;

		game.ProcessInput();

		while (lag >= MillisecondsPerUpdate) {
			game.Update();
			updates_processed++;
			lag -= MillisecondsPerUpdate;
		}

		game.Render();
	}
}