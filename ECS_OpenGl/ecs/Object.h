#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <memory>

#include "../my_math/Vec3.h"

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

	void SetComponent(Camera camera);

	void SetPointLight(Light point);

	void SetSpotLight(Light spot);

	void SetFading(float constant, float linear, float quadratic);

	void SetFading(Vec3 fading);

	void SetCutOff(float cutOff);

	void SetOuterCutOff(float outerCutOff);

	void SetShininess(float shininess);

	void SetComponent(Vec3 position);

	std::shared_ptr<Shader> GetShader();

	void SetLight(Vec3 positions[]);

	void Setup();

	void Draw();

	void DrawLight();
private:
	unsigned int id = 0;
};

#endif