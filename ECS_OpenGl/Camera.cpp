#include "Camera.h"

float Radians(float number) {
	return number * static_cast<float>(0.01745329251994329576923690768489);
}

Camera::Camera() {
	positionCamera = Vec3(0.0f, 0.0f, 3.0f);
	frontCamera = Vec3(0.0f, 0.0f, -1.0f);
	upCamera = Vec3(0.0f, 1.0f, 0.0f);
	pitch = 0.0f;
	yaw = -90.0f;

	UpdateCameraVectors();
}

Mat4 Camera::GetViewMatrix() {
	Mat4 result;
	return result.LookAt(positionCamera, positionCamera + frontCamera, upCamera);
}

Mat4 Camera::GetProjectionMatrix() {
	Mat4 result;
	return result.Perspective(45.0f, (float)800 / (float)600, 0.1f, 100.0f);
}

Vec3 Camera::GetPosition() {
	return positionCamera;
}

Vec3 Camera::GetFront() {
	return frontCamera;
}

Vec3 Camera::GetRight() {
	return right;
}

float Camera::GetSpeed() {
	return speed;
}

std::pair<float, float> Camera::GetPos() {
	return std::pair<float, float>(xPos, yPos);
}

Mat4 Camera::GetViewSkyBox() {
	Mat4 result = GetViewMatrix();
	result.data[3][0] = 0;
	result.data[3][1] = 0;
	result.data[3][2] = 0;
	result.data[3][3] = 0;

	return result;
}

float Camera::GetYaw() {
	return yaw;
}

float Camera::GetPitch() {
	return pitch;
}

void Camera::SetPosition(Vec3 position) {
	positionCamera = position;
}

void Camera::SetPos(std::pair<float, float> pos) {
	xPos = pos.first;
	yPos = pos.second;
}

void Camera::SetYaw(float yaw) {
	this->yaw = yaw;
}

void Camera::SetPitch(float pitch) {
	this->pitch = pitch;
}

void Camera::UpdateCameraVectors() {
	Vec3 front;
	front.x = cos(Radians(yaw)) * cos(Radians(pitch));
	front.y = sin(Radians(pitch));
	front.z = sin(Radians(yaw)) * cos(Radians(pitch));
	frontCamera = front.Normalize();
	right = (frontCamera.CrossProduct(upCamera)).Normalize();
}