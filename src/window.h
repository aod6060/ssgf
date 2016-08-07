#ifndef WINDOW_H
#define WINDOW_H


namespace ssgf {
	namespace win {

		class IApp {
		public:
			virtual void create() = 0;
			virtual void destroy() = 0;
			virtual void render() = 0;
			virtual void update() = 0;
		};

		void create(std::string cap, Uint32 width, Uint32 height, IApp* app = 0);

		void destroy();

		void run();

		void exit();

		int getWidth();

		int getHeight();

	}
}
#endif
