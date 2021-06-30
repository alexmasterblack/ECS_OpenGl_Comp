#pragma once
#include <cmath>

class Vec2 {
public:
	Vec2() = default;
	Vec2(float);
	Vec2(float, float);
	Vec2(const Vec2&);
	Vec2 operator+(const Vec2&) const;
	Vec2& operator+=(const Vec2&);
	Vec2 operator-(const Vec2&) const;
	Vec2& operator-=(const Vec2&);
	Vec2 operator*(float) const;
	Vec2& operator*=(float);
	Vec2 operator/(float) const;
	Vec2& operator/=(float);
	friend const bool operator==(const Vec2&, const Vec2&);
	friend const bool operator!=(const Vec2&, const Vec2&);
	Vec2 Normalize();
	float DotProduct(const Vec2&);
	float Lenght();

	float x = 0, y = 0;
};