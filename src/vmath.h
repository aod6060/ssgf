#ifndef VMATH_H
#define VMATH_H


namespace ssgf {
	namespace math {
		/*
			Vec2

			This structure represents a 2D Vector
		*/
		struct Vec2 {
			float x;
			float y;
			Vec2();
			Vec2(float x, float y);
			Vec2 operator + (const Vec2& v);
			Vec2 operator - (const Vec2& v);
			Vec2 operator * (float f);
			Vec2 operator / (float f);
			Vec2& operator = (const Vec2& v);
			Vec2& operator += (const Vec2& v);
			Vec2& operator -= (const Vec2& v);
			Vec2& operator *= (float f);
			Vec2& operator /= (float f);
			Vec2 operator -();
		};
		/*
			Vec3

			This structure represents a 3D Vector
		*/
		struct Vec3 {
			float x;
			float y;
			float z;
			Vec3();
			Vec3(float x, float y, float z);
			Vec3 operator + (const Vec3& v);
			Vec3 operator - (const Vec3& v);
			Vec3 operator * (float f);
			Vec3 operator / (float f);
			Vec3& operator = (const Vec3& v);
			Vec3& operator += (const Vec3& v);
			Vec3& operator -= (const Vec3& v);
			Vec3& operator *= (float f);
			Vec3& operator /= (float f);
			Vec3 operator -();
		};
		/*
			Vec4

			This structure represents a 4D Vector
		*/
		struct Vec4 {
			float x;
			float y;
			float z;
			float w;
			Vec4();
			Vec4(float x, float y, float z, float w);
			Vec4 operator + (const Vec4& v);
			Vec4 operator - (const Vec4& v);
			Vec4 operator * (float f);
			Vec4 operator / (float f);
			Vec4& operator = (const Vec4& v);
			Vec4& operator += (const Vec4& v);
			Vec4& operator -= (const Vec4& v);
			Vec4& operator *= (float f);
			Vec4& operator /= (float f);
			Vec4 operator -();
		};
		// Length
		float length(const Vec2& v);
		float length(const Vec3& v);
		float length(const Vec4& v);
		// Length2
		float length2(const Vec2& v);
		float length2(const Vec3& v);
		float length2(const Vec4& v);
		// Unit
		Vec2 unit(Vec2 v);
		Vec3 unit(Vec3 v);
		Vec4 unit(Vec4 v);
		// Dot
		float dot(const Vec2& v, const Vec2& v1);
		float dot(const Vec3& v, const Vec3& v1);
		float dot(const Vec4& v, const Vec4& v1);
		// Angle
		float angle(const Vec2& v, const Vec2& v1);
		float angle(const Vec3& v, const Vec3& v1);
		float angle(const Vec4& v, const Vec4& v1);
		// Cross
		Vec3 cross(const Vec3& v, const Vec3& v1);
		// Print Streams
		std::ostream& operator << (std::ostream& os, const Vec2& v);
		std::ostream& operator << (std::ostream& os, const Vec3& v);
		std::ostream& operator << (std::ostream& os, const Vec4& v);
	}
}
#endif
