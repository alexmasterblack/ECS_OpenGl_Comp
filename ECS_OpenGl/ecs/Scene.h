#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include <memory>

#include "../TextureLoading.h"
#include "../Shader.h"
#include "../Camera.h"
#include "../Light.h"
#include "Object.h"
#include "Render.h"
#include "../objects/Cube.h"
#include "../objects/PointLight.h"
#include "../objects/SkyBox.h"

class Scene {
public:
	Scene() = default;

	~Scene();

	void Setup();

	void Lighting(Camera& camera);

	void Draw();
private:
	std::vector<Object> objects;
	std::shared_ptr<SkyBox> skybox;

	Render render;

	Vec3 positionsCube[2];
	Vec3 positionsPoint[3];

	Shader shaderPoint;
	Shader shaderCube;
	Shader shaderSkyBox;

	TextureLoading textureCube;
	TextureLoading textureSkyBox;
};

#endif