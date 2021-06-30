#ifndef POINT_H
#define POINT_H

#include "../my_math/Vec3.h"
#include "../TextureLoading.h"
#include "../Shader.h"
#include "../VertexArraysObject.h"

class PointLight {
public:
	PointLight() = default;

	PointLight(Vec3 position);

	void SetPosition(Vec3 position);

	Vec3 GetPosition();

	void Setup();

	void Draw(std::shared_ptr<Shader> shader);
private:
	Vec3 position;
	VertexArraysObject VAO;
};

#endif