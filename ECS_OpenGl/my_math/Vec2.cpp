#include "Vec2.h"

Vec2::Vec2(float number) :
	x(number), y(number) {}

Vec2::Vec2(float x, float y) :
	x(x), y(y) {}

Vec2::Vec2(const Vec2& other)
{
	x = other.x;
	y = other.y;
}

Vec2 Vec2::operator+(const Vec2& other) const
{
	return Vec2(x + other.x, y + other.y);
}

Vec2& Vec2::operator+=(const Vec2& other)
{
	*this = *this + other;
	return *this;
}

Vec2 Vec2::operator-(const Vec2& other) const
{
	return Vec2(x - other.x, y - other.y);
}

Vec2& Vec2::operator-=(const Vec2& other)
{
	*this = *this - other;
	return *this;
}

Vec2 Vec2::operator*(float number) const
{
	return Vec2(x * number, y * number);
}

Vec2& Vec2::operator*=(float number)
{
	x = x * number;
	y = y * number;

	return *this;
}

Vec2 Vec2::operator/(float number) const
{
	return Vec2(x / number, y / number);
}

Vec2& Vec2::operator/=(float number)
{
	x = x / number;
	y = y / number;

	return *this;
}

Vec2 Vec2::Normalize()
{
	float inversion = 1 / Lenght();
	return Vec2(x * inversion, y * inversion);
}

float Vec2::DotProduct(const Vec2& other)
{
	return x * other.x + y * other.y;
}

float Vec2::Lenght()
{
	return sqrt((pow(x, 2) + pow(y, 2)));
}

const bool operator==(const Vec2& our, const Vec2& other)
{
	return our.x == other.x && our.y == our.y;
}

const bool operator!=(const Vec2& our, const Vec2& other)
{
	return !(our == other);
}
