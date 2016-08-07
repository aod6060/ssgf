#ifndef GAME_H
#define GAME_H

#include "sys.h"

class Game : public ssgf::win::IApp {
private:
	ssgf::graphics::Render2D render2D;
	ssgf::graphics::Transform transform;
public:
	virtual void create();
	virtual void destroy();
	virtual void render();
	virtual void update();
};

#endif
