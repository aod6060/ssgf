#include "sys.h"
#include "game.h"

/*
	This is the main file for the framework. Its also were 
	I'll need for each game.
*/
int main(int argc, char** argv) {
	Game game;

	ssgf::win::create("Test", 640, 480, &game);

	ssgf::win::run();

	ssgf::win::destroy();

	return 0;
}