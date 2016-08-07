#include "sys.h"

static Uint32 g_width;
static Uint32 g_height;
static bool g_run = true;
static SDL_Window* g_window;
static SDL_GLContext g_context;
static ssgf::win::IApp* g_app = 0;

namespace ssgf {
	namespace win {
		void create(std::string cap, Uint32 width, Uint32 height, IApp* app) {
			g_width = width;
			g_height = height;
			g_app = app;
			// Setup SDL
			SDL_Init(SDL_INIT_EVERYTHING);
			// OpenGL Context and Double Buffer 2.1
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
			// Create Window
			g_window = SDL_CreateWindow(
				cap.c_str(),
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				g_width,
				g_height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
			);
			// Context
			g_context = SDL_GL_CreateContext(g_window);
			glewInit();

			// Init Other stuff
			input::create();
			// App Create
			if (g_app != 0) {
				g_app->create();
			}
		}

		void destroy() {
			if (g_app != 0) {
				g_app->destroy();
			}

			SDL_GL_DeleteContext(g_context);
			SDL_DestroyWindow(g_window);
			SDL_Quit();
		}

		void run() {
			SDL_Event e;

			while (g_run) {

				while (SDL_PollEvent(&e)) {
					if (e.type == SDL_QUIT) {
						exit();
					}

					// Do Input stuff
					input::doEvent(e);
				}

				if (g_app != 0) {
					g_app->update();

					g_app->render();
				}

				input::update();

				SDL_GL_SwapWindow(g_window);
			}
		}

		void exit() {
			g_run = false;
		}

		int getWidth() {
			return g_width;
		}

		int getHeight() {
			return g_height;
		}
	}
}