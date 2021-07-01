#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <memory>

#include "../my_math/Vec3.h"

#include "../Shader.h"
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

	void SetComponent(Vec3 position);

	std::shared_ptr<Shader> GetShader();

	void Setup();

	void Draw();

	void DrawLight();
private:
	unsigned int id = 0;
};

#endif