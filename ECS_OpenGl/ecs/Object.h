#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../my_math/Vec3.h"
#include "../InputManager.h"
#include "../Shader.h"
#include "../Light.h"
#include "../objects/Cube.h"
#include "../objects/PointLight.h"
#include "Component.h"

static Component componets;

class Object {
public:
	Object();

	unsigned int GetId();

	void SetComponent(std::shared_ptr<Cube> cube);

	void SetComponent(std::shared_ptr<PointLight> point);

	void SetComponent(std::shared_ptr<Shader> shader);

	void SetComponent(std::shared_ptr<SkyBox> skybox);

	void SetComponent(InputManager input);

	void SetComponent(Camera camera);

	void SetComponent(Vec3 position);

	void SetPointLight(Light point);

	void SetSpotLight(Light spot);

	void SetDirectLight(Light directional);

	void SetEvent(sf::Event event);

	void SetFading(float constant, float linear, float quadratic);

	void SetFading(Vec3 fading);

	void SetCutOff(float cutOff);

	void SetOuterCutOff(float outerCutOff);

	void SetShininess(float shininess);

	void SetCamPos(Vec3 position);

	void SetCamFront(Vec3 front);

	void SetCamUp(Vec3 up);

	void SetCamYaw(float yaw);

	void SetCamPitch(float pitch);

	void SetMouse(std::pair<int, int> mouse);

	void SetSpeed(float speed);

	void SetSpeedMouse(float speedMouse);

	std::shared_ptr<Shader> GetShader();

	void ReadInput(bool& flag);

	void SetLight();

	void Setup();

	void Draw();

	void DrawLight();

	void DrawSkyBox();
private:
	unsigned int id = 0;
};

#endif