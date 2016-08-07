#include "sys.h"

namespace ssgf {
	namespace math {
		// Vec2
		Vec2::Vec2() {
			x = 0;
			y = 0;
		}
		Vec2::Vec2(float x, float y) {
			this->x = x;
			this->y = y;
		}
		Vec2 Vec2::operator + (const Vec2& v) {
			return Vec2(x + v.x, y + v.y);
		}
		Vec2 Vec2::operator - (const Vec2& v) {
			return Vec2(x - v.x, y - v.y);
		}
		Vec2 Vec2::operator * (float f) {
			return Vec2(x * f, y * f);
		}
		Vec2 Vec2::operator / (float f) {
			return Vec2(x / f, y / f);
		}
		Vec2& Vec2::operator = (const Vec2& v) {
			this->x = v.x;
			this->y = v.y;
			return *(this);
		}
		Vec2& Vec2::operator += (const Vec2& v) {
			this->x += v.x;
			this->y += v.y;
			return *(this);
		}
		Vec2& Vec2::operator -= (const Vec2& v) {
			this->x -= v.x;
			this->y -= v.y;
			return *(this);
		}
		Vec2& Vec2::operator *= (float f) {
			this->x *= f;
			this->y *= f;
			return *(this);
		}
		Vec2& Vec2::operator /= (float f) {
			this->x /= f;
			this->y /= f;
			return *(this);
		}
		Vec2 Vec2::operator -() {
			return Vec2(-x, -y);
		}
		// Vec3
		Vec3::Vec3() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}
		Vec3::Vec3(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Vec3 Vec3::operator + (const Vec3& v) {
			return Vec3(x + v.x, y + v.y, z + v.z);
		}
		Vec3 Vec3::operator - (const Vec3& v) {
			return Vec3(x - v.x, y - v.y, z - v.z);
		}
		Vec3 Vec3::operator * (float f) {
			return Vec3(x * f, y * f, z * f);
		}
		Vec3 Vec3::operator / (float f) {
			return Vec3(x / f, y / f, z / f);
		}
		Vec3& Vec3::operator = (const Vec3& v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *(this);
		}
		Vec3& Vec3::operator += (const Vec3& v) {
			this->x += v.x;
			this->y += v.y;
			this->z += v.z;
			return *(this);
		}
		Vec3& Vec3::operator -= (const Vec3& v) {
			this->x -= v.x;
			this->y -= v.y;
			this->z -= v.z;
			return *(this);
		}
		Vec3& Vec3::operator *= (float f) {
			this->x *= f;
			this->y *= f;
			this->z *= f;
			return *(this);
		}
		Vec3& Vec3::operator /= (float f) {
			this->x /= f;
			this->y /= f;
			this->z /= f;
			return *(this);
		}
		Vec3 Vec3::operator -() {
			return Vec3(-x, -y, -z);
		}
		// Vec4
		Vec4::Vec4() {
			this->x = 0;
			this->y = 0;
			this->z = z;
			this->w = w;
		}
		Vec4::Vec4(float x, float y, float z, float w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
		Vec4 Vec4::operator + (const Vec4& v) {
			return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
		}
		Vec4 Vec4::operator - (const Vec4& v) {
			return Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
		}
		Vec4 Vec4::operator * (float f) {
			return Vec4(x * f, y * f, z * f, w * f);
		}
		Vec4 Vec4::operator / (float f) {
			return Vec4(x / f, y / f, z / f, w / f);
		}
		Vec4& Vec4::operator = (const Vec4& v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;
			return *(this);
		}
		Vec4& Vec4::operator += (const Vec4& v) {
			this->x += v.x;
			this->y += v.y;
			this->z += v.z;
			this->w += v.w;
			return *(this);
		}
		Vec4& Vec4::operator -= (const Vec4& v) {
			this->x -= v.x;
			this->y -= v.y;
			this->z -= v.z;
			this->w -= v.w;
			return *(this);
		}
		Vec4& Vec4::operator *= (float f) {
			this->x *= f;
			this->y *= f;
			this->z *= f;
			this->w *= f;
			return *(this);
		}
		Vec4& Vec4::operator /= (float f) {
			this->x /= f;
			this->y /= f;
			this->z /= f;
			this->w /= f;
			return *(this);
		}
		Vec4 Vec4::operator -() {
			return Vec4(-x, -y, -z, -w);
		}
		// Length
		float length(const Vec2& v) {
			return sqrt(v.x * v.x + v.y * v.y);
		}
		float length(const Vec3& v) {
			return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		}
		float length(const Vec4& v) {
			return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
		}
		// Length2
		float length2(const Vec2& v) {
			return v.x * v.x + v.y * v.y;
		}
		float length2(const Vec3& v) {
			return v.x * v.x + v.y * v.y + v.z * v.z;
		}
		float length2(const Vec4& v) {
			return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
		}
		// Unit
		Vec2 unit(Vec2 v) {
			float l = length(v);
			return v / l;
		}
		Vec3 unit(Vec3 v) {
			float l = length(v);
			return v / l;
		}
		Vec4 unit(Vec4 v) {
			float l = length(v);
			return v / l;
		}
		// Dot
		float dot(const Vec2& v, const Vec2& v1) {
			return v.x * v1.x + v.y * v1.y;
		}
		float dot(const Vec3& v, const Vec3& v1) {
			return v.x * v1.x + v.y * v1.y + v.z * v1.z;
		}
		float dot(const Vec4& v, const Vec4& v1) {
			return v.x * v1.x + v.y * v1.y + v.z * v1.z + v.w * v1.w;
		}
		// Angle
		float angle(const Vec2& v, const Vec2& v1) {
			float adotb = dot(v, v1);
			float la = length(v);
			float lb = length(v1);
			return (float)acos(adotb / (la * lb));
		}
		float angle(const Vec3& v, const Vec3& v1) {
			float adotb = dot(v, v1);
			float la = length(v);
			float lb = length(v1);
			return (float)acos(adotb / (la * lb));
		}
		float angle(const Vec4& v, const Vec4& v1) {
			float adotb = dot(v, v1);
			float la = length(v);
			float lb = length(v1);
			return (float)acos(adotb / (la * lb));
		}
		// Cross
		Vec3 cross(const Vec3& v, const Vec3& v1) {
			return Vec3(
				v.y * v1.z - v.z * v1.y,
				v.z * v1.x - v.x * v1.z,
				v.x * v1.y - v.y * v1.x
			);
		}
		// Stream
		std::ostream& operator << (std::ostream& os, const Vec2& v) {
			os << "[" << v.x << ", " << v.y << "]";
			return os;
		}
		std::ostream& operator << (std::ostream& os, const Vec3& v) {
			os << "[" << v.x << ", " << v.y << ", " << v.z <<"]";
			return os;
		}
		std::ostream& operator << (std::ostream& os, const Vec4& v) {
			os << "[" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]";
			return os;
		}
	}
}