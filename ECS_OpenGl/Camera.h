#ifndef CAMERA_H
#define CAMERA_H

#include "my_math/Vec3.h"
#include "my_math/Vec4.h"
#include "my_math/Mat4.h"

class Camera {
public:
	Camera();

	Mat4 GetViewMatrix();

	Mat4 GetProjectionMatrix();

	Vec3 GetPosition();

	Vec3 GetFront();

	Vec3 GetRight();

	float GetSpeed();

	std::pair<float, float> GetPos();

	Mat4 GetViewSkyBox();

	float GetYaw();

	float GetPitch();

	void SetPosition(Vec3 position);

	void SetPos(std::pair<float, float> pos);

	void SetYaw(float yaw);

	void SetPitch(float pitch);

	void UpdateCameraVectors();
private:
	Vec3 positionCamera;
	Vec3 frontCamera;
	Vec3 upCamera;
	Vec3 right;
	Vec3 up;

	float speed = 0.05f;
	float speedMouse = 0.0005f;
	float yaw;
	float pitch;
	float xPos = 800 / 2.0f;
	float yPos = 600 / 2.0f;
	bool mouseMove = true;

	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
};

#endif