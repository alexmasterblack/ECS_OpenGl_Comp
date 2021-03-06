#ifndef POINT_H
#define POINT_H

#include <memory>
#include <string>

#include "../my_math/Vec3.h"
#include "../TextureLoading.h"
#include "../Shader.h"
#include "../VertexArraysObject.h"
#include "../Camera.h"
#include "../Light.h"

class PointLight {
public:
	PointLight() = default;

	void Setup();

	void Draw(std::shared_ptr<Shader> shader, Vec3 position, Camera camera);
private:
	VertexArraysObject VAO;
};

#endif