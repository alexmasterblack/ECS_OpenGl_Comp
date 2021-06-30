#include "Vec4.h"

Vec4::Vec4(float number) :
	x(number), y(number), z(number), w(number) {}

Vec4::Vec4(float x, float y, float z, float w) :
	x(x), y(y), z(z), w(w) {}

Vec4::Vec4(const Vec4& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
}

Vec4 Vec4::operator+(const Vec4& other) const
{
	return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vec4& Vec4::operator+=(const Vec4& other)
{
	*this = *this + other;
	return *this;
}

Vec4 Vec4::operator-(const Vec4& other) const
{
	return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}

Vec4& Vec4::operator-=(const Vec4& other)
{
	*this = *this - other;
	return *this;
}

Vec4 Vec4::operator*(float number) const
{
	return Vec4(x * number, y * number, z * number, w * number);
}

Vec4& Vec4::operator*=(float number)
{
	x = x * number;
	y = y * number;
	z = z * number;
	w = w * number;

	return *this;
}

Vec4 Vec4::operator/(float number) const
{
	return Vec4(x / number, y / number, z / number, w / number);
}

Vec4& Vec4::operator/=(float number)
{
	x = x / number;
	y = y / number;
	z = z / number;
	w = w / number;

	return *this;
}

Vec4 Vec4::Normalize()
{
	float inversion = 1 / Lenght();
	return Vec4(x * inversion, y * inversion, z * inversion, w * inversion);
}

float Vec4::DotProduct(const Vec4& other)
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

float Vec4::Lenght()
{
	return sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2)));
}

const bool operator==(const Vec4& our, const Vec4& other)
{
	return our.x == other.x && our.y == our.y && our.z == other.z && our.w == other.w;
}

const bool operator!=(const Vec4& our, const Vec4& other)
{
	return !(our == other);
}
