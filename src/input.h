#ifndef INPUT_H
#define INPUT_H



namespace ssgf {
	namespace input {
		// Base Functions
		void create();
		void doEvent(const SDL_Event& e);
		void update();
		// Keyboard
		bool isKeyHit(Uint32 k);
		bool isKeyPress(Uint32 k);
	}
}
#endif
