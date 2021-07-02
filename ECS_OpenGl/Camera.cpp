#include "Camera.h"

void Camera::Update(Vec3 position, Vec3 front, Vec3 up) {
	this->position = position;
	this->front = front;
	this->up = up;
}

Mat4 Camera::GetViewMatrix() {
	Mat4 result;
	return result.LookAt(position, position + front, up);
}

Mat4 Camera::GetProjectionMatrix() {
	Mat4 result;
	return result.Perspective(45.0f, (float)800 / (float)600, 0.1f, 100.0f);
}

Vec3 Camera::GetPosition() {
	return position;
}

Vec3 Camera::GetFront() {
	return front;
}

Mat4 Camera::GetViewSkyBox() {
	Mat4 result = GetViewMatrix();
	result.data[3][0] = 0;
	result.data[3][1] = 0;
	result.data[3][2] = 0;
	result.data[3][3] = 0;

	return result;
}