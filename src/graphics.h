#ifndef GRAPHICS_H
#define GRAPHICS_H



namespace ssgf {
	namespace graphics {

		void create();

		void startFrame();

		void endFrame();

		template<typename T>
		class Buffer {
		private:
			std::vector<T> list;
			GLuint id;

		public:
			Buffer() {
				id = 0;
			}

			void add(T t) {
				this->list.push_back(t);
			}

			void clear() {
				this->list.clear();
			}

			void create() {
				glGenBuffers(1, &id);
				bind();
				glBufferData(GL_ARRAY_BUFFER, this->size(), &list[0], GL_STATIC_DRAW);
				unbind();
			}

			void bind() {
				glBindBuffer(GL_ARRAY_BUFFER, id);
			}

			void unbind() {
				glBindBuffer(GL_ARRAY_BUFFER, 0);
			}

			void destroy() {
				glDeleteBuffers(1, &id);
			}

			GLuint typeSize() {
				return sizeof(T);
			}

			GLuint count() {
				return list.size();
			}

			GLuint size() {
				return typeSize() * count();
			}
		};

		class Render2D {
		private:
			Buffer<math::Vec3> vbuf;
			Buffer<math::Vec2> tbuf;
		public:

			void create();

			void render();

			void destroy();
		};

		class Transform {
		private:
			math::Vec2 pos;
			math::Vec2 size;
		public:

			Transform();

			Transform(const math::Vec2& p, const math::Vec2& s);

			void setPos(const math::Vec2& v);

			math::Vec2 getPos();
			
			void setSize(const math::Vec2& v);

			math::Vec2 getSize();

			void push();

			void pop();

		};

		class Texture2D {
		private:
			GLuint id;
			GLuint width;
			GLuint height;
		public:

			Texture2D();

			void create(std::string fn);

			void bind();

			void unbind();

			void destroy();
		};
	}
}
#endif
