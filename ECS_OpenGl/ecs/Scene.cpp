#include "Scene.h"

Scene::~Scene() {
	objects.clear();
}

void Scene::Setup() {
	positionsCube[0] = Vec3(0.0f, 0.0f, 0.0f);
	positionsCube[1] = Vec3(1.5f, 0.2f, -1.5f);

	positionsPoint[0] = Vec3(0.0f, 0.0f, -3.0f);
	positionsPoint[1] = Vec3(1.9f, 0.0f, 2.0f);
	positionsPoint[2] = Vec3(1.3f, 0.0f, -4.0f);


	shaderCube = Shader("files/shaders/lighting.vs", "files/shaders/lighting.fs");
	shaderPoint = Shader("files/shaders/cube.vs", "files/shaders/cube.fs");
	shaderSkyBox = Shader("files/shaders/skybox.vs", "files/shaders/skybox.fs");

	for (int count = 0; count < 2; count++) {
		std::shared_ptr<Cube> cube(new Cube(positionsCube[count]));
		Object object;
		object.SetComponent(cube);
		object.SetComponent(std::make_shared<Shader>(shaderCube));
		objects.push_back(object);
	}

	for (int count = 0; count < 3; count++) {
		std::shared_ptr<PointLight> cube(new PointLight(positionsPoint[count]));
		Object object;
		object.SetComponent(cube);
		object.SetComponent(std::make_shared<Shader>(shaderPoint));
		objects.push_back(object);
	}

	textureCube = TextureLoading("files/images/metall.jpg");

	std::vector<std::string> faces
	{
		"skybox/right.png",
		"skybox/left.png",
		"skybox/top.png",
		"skybox/bottom.png",
		"skybox/front.png",
		"skybox/back.png"
	};

	skybox = std::make_shared<SkyBox>(faces);

	for (int count = 0; count < objects.size(); count++) {
		objects[count].Setup();
	}

	skybox->Setup();
	shaderSkyBox.Use();
	shaderSkyBox.SetInt("skybox", 0);
}

void Scene::Lighting(Camera& camera) {
	render.SetLighting(shaderCube, camera, positionsPoint);
}

void Scene::Draw(Camera& camera) {
	render.DrawCube(shaderCube, camera, objects);

	render.DrawPoint(shaderPoint, camera, objects);

	render.DrawSkyBox(shaderSkyBox, camera, skybox);
}