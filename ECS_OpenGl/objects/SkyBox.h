#ifndef SKYBOX_H
#define SKYBOX_H

#include <memory>

#include "../my_math/Vec3.h"
#include "../Shader.h"
#include "../Camera.h"
#include "../VertexArraysObject.h"
#include "../VertexBufferObjects.h"

class SkyBox {
public:
	SkyBox() = default;

	void Setup(std::shared_ptr<Shader> shader);

	void Draw(std::shared_ptr<Shader> shader, Camera camera);
private:
	VertexArraysObject VAO;
};

#endif