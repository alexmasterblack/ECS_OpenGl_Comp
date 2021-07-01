#ifndef CUBE_H
#define CUBE_H

#include <memory>

#include "../my_math/Vec3.h"
#include "../Shader.h"
#include "../VertexArraysObject.h"
#include "../VertexBufferObjects.h"

class Cube {
public:
	Cube() = default;

	void Setup();

	void Draw(std::shared_ptr<Shader> shader, Vec3 position);
private:
	VertexArraysObject VAO;
};

#endif