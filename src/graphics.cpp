#include "sys.h"

namespace ssgf {
	namespace graphics {
		void create() {
			glDisable(GL_DEPTH_TEST);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		void startFrame() {
			glClear(GL_COLOR_BUFFER_BIT);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(0.0f, win::getWidth(), win::getHeight(), 0.0f, -1.0f, 1.0f);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}

		void endFrame() {
			// Do Nothing for now
		}

		// Render2D
		void Render2D::create() {
			// Vertex Buffer
			vbuf.add(math::Vec3(0.0f, 0.0f, 0.0f));
			vbuf.add(math::Vec3(1.0f, 0.0f, 0.0f));
			vbuf.add(math::Vec3(0.0f, 1.0f, 0.0f));
			vbuf.add(math::Vec3(0.0f, 1.0f, 0.0f));
			vbuf.add(math::Vec3(1.0f, 0.0f, 0.0f));
			vbuf.add(math::Vec3(1.0f, 1.0f, 0.0f));
			vbuf.create();
			// Texture Coord Buffer
			tbuf.add(math::Vec2(0.0f, 0.0f));
			tbuf.add(math::Vec2(1.0f, 0.0f));
			tbuf.add(math::Vec2(0.0f, 1.0f));
			tbuf.add(math::Vec2(0.0f, 1.0f));
			tbuf.add(math::Vec2(1.0f, 0.0f));
			tbuf.add(math::Vec2(1.0f, 1.0f));
			tbuf.create();
		}

		void Render2D::render() {
			vbuf.bind();
			glVertexPointer(3, GL_FLOAT, 0, 0);
			tbuf.bind();
			glTexCoordPointer(2, GL_FLOAT, 0, 0);
			tbuf.unbind();
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glDrawArrays(GL_TRIANGLES, 0, vbuf.count());
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			glDisableClientState(GL_VERTEX_ARRAY);
		}

		void Render2D::destroy() {
			vbuf.destroy();
			tbuf.destroy();
		}
		// Transform
		Transform::Transform() {
			this->size = math::Vec2(1, 1);
		}

		Transform::Transform(const math::Vec2& p, const math::Vec2& s) {
			this->pos = p;
			this->size = s;
		}

		void Transform::setPos(const math::Vec2& v) {
			this->pos = v;
		}

		math::Vec2 Transform::getPos() {
			return this->pos;
		}

		void Transform::setSize(const math::Vec2& v) {
			this->size = v;
		}

		math::Vec2 Transform::getSize() {
			return this->size;
		}

		void Transform::push() {
			glPushMatrix();
			glTranslatef(pos.x, pos.y, 0.0f);
			glScalef(size.x, size.y, 0.0f);
		}

		void Transform::pop() {
			glPopMatrix();
		}
		// Texture2D
		Texture2D::Texture2D() {
			this->id = 0;
		}

		void Texture2D::create(std::string fn) {

		}

		void Texture2D::bind() {
			glBindTexture(GL_TEXTURE_2D, id);
		}

		void Texture2D::unbind() {
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		void Texture2D::destroy() {
			glDeleteTextures(1, &id);
		}
	}
}