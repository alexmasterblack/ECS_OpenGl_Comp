#ifndef CUBE_H
#define CUBE_H

#include <memory>

#include "../my_math/Vec3.h"
#include "../TextureLoading.h"
#include "../Shader.h"
#include "../VertexArraysObject.h"
#include "../VertexBufferObjects.h"

class Cube {
public:
	Cube() = default;

	Cube(Vec3 position);

	void SetPosition(Vec3 position);

	Vec3 GetPosition();

	void Setup();

	void Draw(std::shared_ptr<Shader> shader);
private:
	Vec3 position;
	VertexArraysObject VAO;
};

#endif