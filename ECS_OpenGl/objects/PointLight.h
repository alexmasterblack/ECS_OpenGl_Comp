#ifndef POINT_H
#define POINT_H

#include <memory>

#include "../my_math/Vec3.h"
#include "../TextureLoading.h"
#include "../Shader.h"
#include "../VertexArraysObject.h"

class PointLight {
public:
	PointLight() = default;

	void Setup();

	void Draw(std::shared_ptr<Shader> shader, Vec3 position);
private:
	VertexArraysObject VAO;
};

#endif