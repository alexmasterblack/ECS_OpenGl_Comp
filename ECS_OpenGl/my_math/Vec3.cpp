#include "Vec3.h"

Vec3::Vec3(float number) :
	x(number), y(number), z(number) {}

Vec3::Vec3(float x, float y, float z) :
	x(x), y(y), z(z) {}


Vec3::Vec3(const Vec3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

Vec3 Vec3::operator+(const Vec3& other) const
{
	return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3& Vec3::operator+=(const Vec3& other)
{
	*this = *this + other;
	return *this;
}

Vec3 Vec3::operator-(const Vec3& other) const
{
	return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3& Vec3::operator-=(const Vec3& other)
{
	*this = *this - other;
	return *this;
}

Vec3 Vec3::operator*(float number) const
{
	return Vec3(x * number, y * number, z * number);
}

Vec3& Vec3::operator*=(float number)
{
	x = x * number;
	y = y * number;
	z = z * number;

	return *this;
}

Vec3 Vec3::operator/(float number) const
{
	return Vec3(x / number, y / number, z / number);
}

Vec3& Vec3::operator/=(float number)
{
	x = x / number;
	y = y / number;
	z = z / number;

	return *this;
}

Vec3 Vec3::Normalize()
{
	float inversion = 1 / Lenght();
	return Vec3(x * inversion, y * inversion, z * inversion);
}

float Vec3::DotProduct(const Vec3& other)
{
	return x * other.x + y * other.y + z * other.z;
}

Vec3 Vec3::CrossProduct(const Vec3& other)
{
	return Vec3(y * other.z - other.y * z, z * other.x - other.z * x, x * other.y - other.x * y);
}

float Vec3::Lenght()
{
	return sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

const bool operator==(const Vec3& our, const Vec3& other)
{
	return our.x == other.x && our.y == our.y && our.z == other.z;
}

const bool operator!=(const Vec3& our, const Vec3& other)
{
	return !(our == other);
}
