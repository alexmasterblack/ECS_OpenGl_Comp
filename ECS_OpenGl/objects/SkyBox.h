#ifndef SKYBOX_H
#define SKYBOX_H

#include "../my_math/Vec3.h"
#include "../TextureLoading.h"
#include "../VertexArraysObject.h"
#include "../VertexBufferObjects.h"

class SkyBox {
public:
	SkyBox() = default;

	SkyBox(std::vector<std::string> faces);

	void Setup();

	void Draw();
private:
	TextureLoading texture;
	VertexArraysObject VAO;
};

#endif