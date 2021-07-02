#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../TextureLoading.h"
#include "../Shader.h"
#include "../Camera.h"
#include "../Light.h"
#include "../InputManager.h"
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

	void Event(sf::Event event, bool& flag);

	void Lighting();

	void Draw();
private:
	std::vector<Object> objects;
	std::shared_ptr<SkyBox> skybox;

	Render render;
	Object input;

	Vec3 positionsCube[2];
	Vec3 positionsPoint[3];

	Shader shaderPoint;
	Shader shaderCube;
	Shader shaderSkyBox;

	TextureLoading textureCube;
	TextureLoading textureSkyBox;
};

#endif