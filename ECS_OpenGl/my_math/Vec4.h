#pragma once
#include <cmath>

class Vec4 {
public:
	Vec4() = default;
	Vec4(float);
	Vec4(float, float, float, float);
	Vec4(const Vec4&);
	Vec4 operator+(const Vec4&) const;
	Vec4& operator+=(const Vec4&);
	Vec4 operator-(const Vec4&) const;
	Vec4& operator-=(const Vec4&);
	Vec4 operator*(float) const;
	Vec4& operator*=(float);
	Vec4 operator/(float) const;
	Vec4& operator/=(float);
	friend const bool operator==(const Vec4&, const Vec4&);
	friend const bool operator!=(const Vec4&, const Vec4&);
	Vec4 Normalize();
	float DotProduct(const Vec4&);
	float Lenght();

	float x = 0, y = 0, z = 0, w = 0;
};