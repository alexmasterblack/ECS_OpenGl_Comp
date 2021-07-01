#ifndef RENDER_H
#define RENDER_H

#include <vector>
#include <map>

#include "../Shader.h"
#include "Object.h"
#include "../objects/SkyBox.h"
#include "../my_math/Vec3.h"

class Render {
public:
	Render() = default;

	void DrawCube(std::vector<Object> objects);

	void DrawPoint(std::vector<Object> objects);

	void DrawSkyBox(Shader& shader, Camera& camera, std::shared_ptr<SkyBox> skybox);

	void SetLighting(std::vector<Object> objects);
private:
};

#endif