#pragma once
#include <cmath>

class Vec3 {
public:
	Vec3() = default;
	Vec3(float);
	Vec3(float, float, float);
	Vec3(const Vec3&);
	Vec3 operator+(const Vec3&) const;
	Vec3& operator+=(const Vec3&);
	Vec3 operator-(const Vec3&) const;
	Vec3& operator-=(const Vec3&);
	Vec3 operator*(float) const;
	Vec3& operator*=(float);
	Vec3 operator/(float) const;
	Vec3& operator/=(float);
	friend const bool operator==(const Vec3&, const Vec3&);
	friend const bool operator!=(const Vec3&, const Vec3&);
	Vec3 Normalize();
	float DotProduct(const Vec3&);
	Vec3 CrossProduct(const Vec3&);
	float Lenght();

	float x = 0, y = 0, z = 0;
};