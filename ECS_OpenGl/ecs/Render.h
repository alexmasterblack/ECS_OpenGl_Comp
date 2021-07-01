#ifndef RENDER_H
#define RENDER_H

#include <vector>
#include <map>

#include "../TextureLoading.h"
#include "../VertexArraysObject.h"
#include "../VertexBufferObjects.h"
#include "../Shader.h"
#include "Object.h"
#include "../Light.h"
#include "../Camera.h"
#include "../objects/SkyBox.h"

#include <GL/glew.h>
#include "../glm/gtc/matrix_transform.hpp"

#include "../my_math/Vec3.h"


class Render {
public:
	Render() = default;

	void DrawCube(Shader& shader, Camera& camera, std::vector<Object> objects);

	void DrawPoint(Shader& shader, Camera& camera, std::vector<Object> objects);

	void DrawSkyBox(Shader& shader, Camera& camera, std::shared_ptr<SkyBox> skybox);

	void SetLighting(std::vector<Object> objects, Vec3 positionsPoint[]);
private:
};

#endif