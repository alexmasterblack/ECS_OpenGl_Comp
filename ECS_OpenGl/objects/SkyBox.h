#ifndef SKYBOX_H
#define SKYBOX_H

#include "../my_math/Vec3.h"
#include "../VertexArraysObject.h"
#include "../VertexBufferObjects.h"

class SkyBox {
public:
	SkyBox() = default;

	void Setup();

	void Draw();
private:
	VertexArraysObject VAO;
};

#endif