#ifndef CUBE_H
#define CUBE_H

#include <memory>

#include "../my_math/Vec3.h"
#include "../Shader.h"
#include "../VertexArraysObject.h"
#include "../VertexBufferObjects.h"
#include "../Camera.h"
#include "../Light.h"

class Cube {
public:
	Cube() = default;

	void Setup();

	void SetPointLighting(std::shared_ptr<Shader> shader, std::vector<Vec3> positions, Vec3 fading, Camera camera, Light point, float shininess);

	void SetSpotLighting(std::shared_ptr<Shader> shader, Vec3 fading, Camera camera, Light spot, float cutOff, float outerCutOff);

	void Draw(std::shared_ptr<Shader> shader, Vec3 position, Camera camera);
private:
	VertexArraysObject VAO;

	unsigned int count = 0;
};

#endif