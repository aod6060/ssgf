#include "game.h"

void Game::create() {
	ssgf::graphics::create();
	render2D.create();
	transform.setPos(ssgf::math::Vec2(32.0f, 32.0f));
	transform.setSize(ssgf::math::Vec2(32.0f, 32.0f));
}

void Game::destroy() {
	render2D.destroy();
}

void Game::render() {
	ssgf::graphics::startFrame();
	transform.push();
	render2D.render();
	transform.pop();
	ssgf::graphics::endFrame();
}

void Game::update() {

	if (ssgf::input::isKeyHit(SDL_SCANCODE_ESCAPE)) {
		ssgf::win::exit();
	}


	if (ssgf::input::isKeyHit(SDL_SCANCODE_LEFT)) {
		std::cout << "Hello, From Left Key." << std::endl;
	}

	if (ssgf::input::isKeyPress(SDL_SCANCODE_RIGHT)) {
		std::cout << "Hello, From Right Key." << std::endl;
	}
}