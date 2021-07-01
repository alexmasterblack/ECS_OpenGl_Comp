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

	Render(std::vector<Object> objects);

	void Draw();

	void SetLighting();
private:
	std::vector<Object> objects;
};

#endif