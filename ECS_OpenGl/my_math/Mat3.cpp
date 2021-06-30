#include "Mat3.h"

Mat3::Mat3(float number)
{
	data[0][0] = number;
	data[0][1] = 0;
	data[0][2] = 0;
	data[1][0] = 0;
	data[1][1] = number;
	data[1][2] = 0;
	data[2][0] = 0;
	data[2][1] = 0;
	data[2][2] = number;
}

Mat3::Mat3(
	float x, float y, float z,
	float w, float a, float b,
	float c, float d, float e)
{
	data[0][0] = x;
	data[0][1] = y;
	data[0][2] = z;
	data[1][0] = w;
	data[1][1] = a;
	data[1][2] = b;
	data[2][0] = c;
	data[2][1] = d;
	data[2][2] = e;
}

Mat3::Mat3(const Vec3& first, const Vec3& second, const Vec3& third)
{
	data[0][0] = first.x;
	data[0][1] = first.y;
	data[0][2] = first.z;
	data[1][0] = second.x;
	data[1][1] = second.y;
	data[1][2] = second.z;
	data[2][0] = third.x;
	data[2][1] = third.y;
	data[2][2] = third.z;
}

Mat3::Mat3(const Mat3& other)
{
	data = other.data;
}

Mat3 Mat3::operator+(const Mat3& other) const
{
	Mat3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			result.data[i][j] = data[i][j] + other.data[i][j];
	}
	return result;
}

Mat3& Mat3::operator+=(const Mat3& other)
{
	*this = *this + other;
	return *this;
}

Mat3 Mat3::operator-(const Mat3& other) const
{
	Mat3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			result.data[i][j] = data[i][j] - other.data[i][j];
	}
	return result;
}

Mat3& Mat3::operator-=(const Mat3& other)
{
	*this = *this - other;
	return *this;
}

Mat3 Mat3::operator*(const Mat3& other) const
{
	Mat3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				result.data[i][j] += other.data[i][k] * data[k][j];
			}
		}
	}
	return result.GetTransposed();
}

Mat3& Mat3::operator*=(const Mat3& other)
{
	*this = *this * other;
	return *this;
}

Mat3 Mat3::operator*(float number) const
{
	Mat3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			result.data[i][j] = data[i][j] * number;
	}
	return result;
}

Mat3& Mat3::operator*=(float number)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			data[i][j] *= number;
	}
	return *this;
}

Mat3 Mat3::operator/(float number) const
{
	Mat3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			result.data[i][j] = data[i][j] / number;
	}
	return result;
}

Mat3& Mat3::operator/=(float number)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			data[i][j] /= number;
	}
	return *this;
}

Mat3 Mat3::operator+(float number) const
{
	Mat3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			result.data[i][j] = data[i][j] + number;
	}
	return result;
}

Mat3& Mat3::operator+=(float number)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			data[i][j] += number;
	}
	return *this;
}

Mat3 Mat3::operator-(float number) const
{
	Mat3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			result.data[i][j] = data[i][j] - number;
	}
	return result;
}

Mat3& Mat3::operator-=(float number)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			data[i][j] -= number;
	}
	return *this;
}

Vec3 Mat3::operator*(const Vec3& other) const
{
	Vec3 result;
	result.x = data[0][0] * other.x + data[1][0] * other.y + data[2][0] * other.z;
	result.y = data[0][1] * other.x + data[1][1] * other.y + data[2][1] * other.z;
	result.z = data[0][2] * other.x + data[1][2] * other.y + data[2][2] * other.z;
	return result;
}

Mat3 Mat3::GetIdentity()
{
	return Mat3(1.0f);
}

Mat3 Mat3::GetTransposed()
{
	return Mat3(GetColumn(0), GetColumn(1), GetColumn(2));
}

Mat3 Mat3::GetInverse()
{
	float det = 
		data[0][0] * (data[1][1] * data[2][2] - data[2][1] * data[1][2])
		- data[1][0] * (data[0][1] * data[2][2] - data[2][1] * data[0][2])
		+ data[2][0] * (data[0][1] * data[1][2] - data[1][1] * data[0][2]);

	Mat3 result;
	result.data[0][0] = (data[1][1] * data[2][2] - data[2][1] * data[1][2]) * (1 / det);
	result.data[1][0] = -(data[1][0] * data[2][2] - data[2][0] * data[1][2]) * (1 / det);
	result.data[2][0] = (data[1][0] * data[2][1] - data[2][0] * data[1][1]) * (1 / det);
	result.data[0][1] = -(data[0][1] * data[2][2] - data[2][1] * data[0][2]) * (1 / det);
	result.data[1][1] = (data[0][0] * data[2][2] - data[2][0] * data[0][2]) * (1 / det);
	result.data[2][1] = -(data[0][0] * data[2][1] - data[2][0] * data[0][1]) * (1 / det);
	result.data[0][2] = (data[0][1] * data[1][2] - data[1][1] * data[0][2]) * (1 / det);
	result.data[1][2] = -(data[0][0] * data[1][2] - data[1][0] * data[0][2]) * (1 / det);
	result.data[2][2] = (data[0][0] * data[1][1] - data[1][0] * data[0][1]) * (1 / det);

	return result;
}

Vec3 Mat3::GetColumn(int index)
{
	assert(index >= 0 && index < 3);
	return Vec3(data[index][0], data[index][1], data[index][2]);
}

Vec3 Mat3::GetRow(int index)
{
	assert(index >= 0 && index < 3);
	std::vector<float> result(3);
	for (int i = 0; i < 3; i++) {
		result[i] = data[i][index];
	}
	return Vec3(result[0], result[1], result[2]);
}

const bool operator==(const Mat3& our, const Mat3& other)
{
	return our.data == other.data;
}

const bool operator!=(const Mat3& our, const Mat3& other)
{
	return !(our == other);
}
