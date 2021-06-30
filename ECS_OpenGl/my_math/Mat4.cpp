#include "Mat4.h"

Mat4::Mat4(float number)
{
	data[0][0] = number;
	data[0][1] = 0;
	data[0][2] = 0;
	data[0][3] = 0;
	data[1][0] = 0;
	data[1][1] = number;
	data[1][2] = 0;
	data[1][3] = 0;
	data[2][0] = 0;
	data[2][1] = 0;
	data[2][2] = number;
	data[2][3] = 0;
	data[3][0] = 0;
	data[3][1] = 0;
	data[3][2] = 0;
	data[3][3] = number;
}

Mat4::Mat4(
	float x, float y, float z, float w,
	float a, float b, float c, float d,
	float e, float f, float g, float h,
	float i, float k, float l, float m)
{
	data[0][0] = x;
	data[0][1] = y;
	data[0][2] = z;
	data[0][3] = w;
	data[1][0] = a;
	data[1][1] = b;
	data[1][2] = c;
	data[1][3] = d;
	data[2][0] = e;
	data[2][1] = f;
	data[2][2] = g;
	data[2][3] = h;
	data[3][0] = i;
	data[3][1] = k;
	data[3][2] = l;
	data[3][3] = m;
}

Mat4::Mat4(const Vec4& first, const Vec4& second, const Vec4& third, const Vec4& fifth)
{
	data[0][0] = first.x;
	data[0][1] = first.y;
	data[0][2] = first.z;
	data[0][3] = first.w;
	data[1][0] = second.x;
	data[1][1] = second.y;
	data[1][2] = second.z;
	data[1][3] = second.w;
	data[2][0] = third.x;
	data[2][1] = third.y;
	data[2][2] = third.z;
	data[2][3] = third.w;
	data[3][0] = fifth.x;
	data[3][1] = fifth.y;
	data[3][2] = fifth.z;
	data[3][3] = fifth.w;
}

Mat4::Mat4(const Mat4& other)
{
	data = other.data;
}

Mat4 Mat4::operator+(const Mat4& other) const
{
	Mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			result.data[i][j] = data[i][j] + other.data[i][j];
	}
	return result;
}

Mat4& Mat4::operator+=(const Mat4& other)
{
	*this = *this + other;
	return *this;
}

Mat4 Mat4::operator-(const Mat4& other) const
{
	Mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			result.data[i][j] = data[i][j] - other.data[i][j];
	}
	return result;
}

Mat4& Mat4::operator-=(const Mat4& other)
{
	*this = *this - other;
	return *this;
}

Mat4 Mat4::operator*(const Mat4& other) const
{
	Mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				result.data[i][j] += other.data[i][k] * data[k][j];
			}
		}
	}
	return result.GetTransposed();
}

Mat4& Mat4::operator*=(const Mat4& other)
{
	*this = *this * other;
	return *this;
}

Mat4 Mat4::operator*(float number) const
{
	Mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			result.data[i][j] = data[i][j] * number;
	}
	return result;
}

Mat4& Mat4::operator*=(float number)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			data[i][j] *= number;
	}
	return *this;
}

Mat4 Mat4::operator/(float number) const
{
	Mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			result.data[i][j] = data[i][j] / number;
	}
	return result;
}

Mat4& Mat4::operator/=(float number)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			data[i][j] /= number;
	}
	return *this;
}

Mat4 Mat4::operator+(float number) const
{
	Mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			result.data[i][j] = data[i][j] + number;
	}
	return result;
}

Mat4& Mat4::operator+=(float number)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			data[i][j] += number;
	}
	return *this;
}

Mat4 Mat4::operator-(float number) const
{
	Mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			result.data[i][j] = data[i][j] - number;
	}
	return result;
}

Mat4& Mat4::operator-=(float number)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			data[i][j] -= number;
	}
	return *this;
}

Vec4 Mat4::operator*(const Vec4& other) const
{
	Vec4 result;
	result.x = data[0][0] * other.x + data[1][0] * other.y + data[2][0] * other.z + data[3][0] * other.w;
	result.y = data[0][1] * other.x + data[1][1] * other.y + data[2][1] * other.z + data[3][1] * other.w;
	result.z = data[0][2] * other.x + data[1][2] * other.y + data[2][2] * other.z + data[3][2] * other.w;
	result.w = data[0][3] * other.x + data[1][3] * other.y + data[2][3] * other.z + data[3][3] * other.w;
	return result;
}

Mat4 Mat4::GetIdentity()
{
	return Mat4(1.0f);
}

Mat4 Mat4::GetTransposed()
{
	return Mat4(GetColumn(0), GetColumn(1), GetColumn(2), GetColumn(3));
}

Vec4 Mat4::GetColumn(int index)
{
	assert(index >= 0 && index < 4);
	return Vec4(data[index][0], data[index][1], data[index][2], data[index][3]);
}

Vec4 Mat4::GetRow(int index)
{
	assert(index >= 0 && index < 4);
	std::array<float, 4> result;
	for (int i = 0; i < 4; i++) {
		result[i] = data[i][index];
	}
	return Vec4(result[0], result[1], result[2], result[3]);
}

Mat4 Mat4::Rotate(float angle, Vec3& vec)
{
	float cosAngle = cos(angle);
	float sinAngle = sin(angle);

	Vec3 axis(vec.Normalize());
	Vec3 sup(axis * (1 - cosAngle));

	Mat4 rotate;
	rotate.data[0][0] = cosAngle + sup.x * axis.x;
	rotate.data[0][1] = sup.x * axis.y + sinAngle * axis.z;
	rotate.data[0][2] = sup.x * axis.z - sinAngle * axis.y;
	rotate.data[0][3] = 0;

	rotate.data[1][0] = sup.y * axis.x - sinAngle * axis.z;
	rotate.data[1][1] = cosAngle + sup.y * axis.y;
	rotate.data[1][2] = sup.y * axis.z + sinAngle * axis.x;
	rotate.data[1][3] = 0;

	rotate.data[2][0] = sup.z * axis.x + sinAngle * axis.y;
	rotate.data[2][1] = sup.z * axis.y - sinAngle * axis.x;
	rotate.data[2][2] = cosAngle + sup.z * axis.z;
	rotate.data[2][3] = 0;

	rotate.data[3][0] = 0;
	rotate.data[3][1] = 0;
	rotate.data[3][2] = 0;
	rotate.data[3][3] = 1;

	return Mat4(*this * rotate);
}

Mat4 Mat4::Translate(const Vec3& vec)
{
	Mat4 result(*this);

	result.data[3][0] = data[0][0] * vec.x + data[1][0] * vec.y + data[2][0] * vec.z + data[3][0];
	result.data[3][1] = data[0][1] * vec.x + data[1][1] * vec.y + data[2][1] * vec.z + data[3][1];
	result.data[3][2] = data[0][2] * vec.x + data[1][2] * vec.y + data[2][2] * vec.z + data[3][2];
	result.data[3][3] = data[0][3] * vec.x + data[1][3] * vec.y + data[2][3] * vec.z + data[3][3];

	return result;
}

Mat4 Mat4::Scale(const Vec3& vec)
{
	Mat4 result(*this);

	result.data[0][0] *= vec.x;
	result.data[0][1] *= vec.x;
	result.data[0][2] *= vec.x;
	result.data[0][3] *= vec.x;

	result.data[1][0] *= vec.y;
	result.data[1][1] *= vec.y;
	result.data[1][2] *= vec.y;
	result.data[1][3] *= vec.y;

	result.data[2][0] *= vec.z;
	result.data[2][1] *= vec.z;
	result.data[2][2] *= vec.z;
	result.data[2][3] *= vec.z;

	return result;
}

Mat4 Mat4::LookAt(Vec3 position, Vec3 center, Vec3 up)
{
	Vec3 vecOne(position - center);
	Vec3 zaxis(vecOne.Normalize());

	Vec3 vecUp(up.Normalize());
	Vec3 vecCross(vecUp.CrossProduct(zaxis));
	Vec3 xaxis(vecCross.Normalize());

	Vec3 yaxis(zaxis.CrossProduct(xaxis));

	Mat4 rotation(1.0f);
	rotation.data[0][0] = xaxis.x;
	rotation.data[1][0] = xaxis.y;
	rotation.data[2][0] = xaxis.z;
	rotation.data[0][1] = yaxis.x;
	rotation.data[1][1] = yaxis.y;
	rotation.data[2][1] = yaxis.z;
	rotation.data[0][2] = zaxis.x;
	rotation.data[1][2] = zaxis.y;
	rotation.data[2][2] = zaxis.z;

	Mat4 translation(1.0f);
	translation.data[3][0] = -position.x;
	translation.data[3][1] = -position.y;
	translation.data[3][2] = -position.z;

	return rotation * translation;
}

Mat4 Mat4::Perspective(float fovy, float aspect, float near, float far)
{
	assert(abs(aspect - std::numeric_limits<float>::epsilon()) > 0.0f);

	float tang = tan(fovy / 2.0f);

	Mat4 result(0.0f);
	result.data[0][0] = 1.0f / (aspect * tang);
	result.data[1][1] = 1.0f / (tang);
	result.data[2][2] = -(far + near) / (far - near);
	result.data[2][3] = -1.0f;
	result.data[3][2] = -(2.0f * far * near) / (far - near);
	return result;
}

Mat4 Mat4::Ortho(float left, float right, float bottom, float top)
{
	Mat4 result(1.0f);
	result.data[0][0] = 2.0f / (right - left);
	result.data[1][1] = 2.0f / (top - bottom);
	result.data[2][2] = -1.0f;
	result.data[3][0] = -(right + left) / (right - left);
	result.data[3][1] = -(top + bottom) / (top - bottom);
	return result;
}

const bool operator==(const Mat4& our, const Mat4& other)
{
	return our.data == other.data;
}

const bool operator!=(const Mat4& our, const Mat4& other)
{
	return !(our == other);
}
