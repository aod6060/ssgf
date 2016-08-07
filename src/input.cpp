#include "sys.h"

namespace ssgf {
	namespace input {
		enum InputState {
			IS_RELEASE = 0,
			IS_ONCE,
			IS_PRESSED,
			IS_SIZE
		};

		// Keyboard
		InputState keyStates[SDL_NUM_SCANCODES];

		void onKeyboardEvent(const SDL_KeyboardEvent& e);

		// Base Functions
		void create() {
			for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
				keyStates[i] = IS_RELEASE;
			}
		}

		void doEvent(const SDL_Event& e) {
			switch (e.type) {
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				onKeyboardEvent(e.key);
				break;
			}
		}

		void update() {
			for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
				if (keyStates[i] == IS_ONCE) {
					keyStates[i] = IS_PRESSED;
				}
			}

		}

		// Keyboard
		bool isKeyHit(Uint32 k) {
			return keyStates[k] == IS_ONCE;
		}

		bool isKeyPress(Uint32 k) {
			return keyStates[k] == IS_ONCE || keyStates[k] == IS_PRESSED;
		}

		void onKeyboardEvent(const SDL_KeyboardEvent& e) {
			Uint32 sc = e.keysym.scancode;

			bool pressed = (e.state == SDL_PRESSED) ? true : false;

			if (pressed) {
				if (keyStates[sc] == IS_RELEASE) {
					keyStates[sc] = IS_ONCE;
				}
			}
			else {
				if (keyStates[sc] != IS_RELEASE) {
					keyStates[sc] = IS_RELEASE;
				}
			}
		}
	}
}