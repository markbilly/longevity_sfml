#include "game.h"
#include "scene_loader.h"

Game::Game() {
	fps_ = 0;

	window_ = new sf::RenderWindow(sf::VideoMode(640, 480), "Longevity"); // change window size to scale	
	camera_ = new Camera(window_, sf::IntRect(0, 0, 320, 240));  // view size is 1:1 scale
	input_handler_ = new InputHandler(window_, camera_);

	texture_factory_ = new TextureFactory();
	texture_factory_->RegisterTexture("test", "test.png");

	// Set up scene
	scene_ = new Scene(texture_factory_);
	SceneLoader scene_loader = SceneLoader();
	scene_loader.Load("test_map.txt", *scene_);
	sf::IntRect scene_size = scene_->GetSizeInPixels();
	camera_->SetBoundary(scene_size.width, scene_size.height);
}

Game::~Game() {
	delete camera_;
	delete window_;
	delete scene_;
	delete texture_factory_;
}

sf::RenderWindow* Game::GetWindow() {
	return window_;
}

void Game::ProcessInput() {

	input_handler_->HandleInput();

	//sf::Event event;

	//while (window_->pollEvent(event)) {
	//	if (event.type == sf::Event::Closed) {
	//		window_->close();
	//	}

	//	if (event.type == sf::Event::KeyPressed) {
	//		if (event.key.code == sf::Keyboard::W) {
	//			offset_y_  = -1;
	//		}

	//		if (event.key.code == sf::Keyboard::A) {
	//			offset_x_ = -1;
	//		}

	//		if (event.key.code == sf::Keyboard::S) {
	//			offset_y_ = 1;
	//		}

	//		if (event.key.code == sf::Keyboard::D) {
	//			offset_x_ = 1;
	//		}
	//	}
	//}
}

void Game::Update() {
	if (offset_x_ != 0 || offset_y_ != 0) {
		camera_->Move(offset_x_, offset_y_);
	}

	offset_x_ = 0;
	offset_y_ = 0;
}

void Game::Render() {
	window_->clear();
	scene_->Render(window_);

#ifdef _DEBUG
	RenderFpsText();
#endif
	
	window_->display();
}

void Game::SetFps(int fps) {
	fps_ = fps;
}

void Game::RenderFpsText() {
	sf::Font my_font;

	if (my_font.loadFromFile("font.ttf")) {
		sf::Text text;
		text.setFont(my_font);
		text.setString(std::to_string(fps_));
		text.setCharacterSize(16);
		text.setColor(sf::Color::Red);

		window_->draw(text);
	}
}
