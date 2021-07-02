#ifndef CAMERA_H
#define CAMERA_H

#include "my_math/Vec3.h"
#include "my_math/Vec4.h"
#include "my_math/Mat4.h"

class Camera {
public:
	Camera() = default;

	void Update(Vec3 position, Vec3 front, Vec3 up);

	Mat4 GetViewMatrix();

	Mat4 GetProjectionMatrix();

	Vec3 GetPosition();

	Vec3 GetFront();

	Mat4 GetViewSkyBox();
private:
	Vec3 position;
	Vec3 front;
	Vec3 up;
};

#endif