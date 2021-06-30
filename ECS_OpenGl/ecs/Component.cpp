#include "Component.h"

void Component::PushComponent(std::shared_ptr<Cube> cube, unsigned int id) {
	cubes[id] = cube;
}

void Component::PushComponent(std::shared_ptr<PointLight> point, unsigned int id) {
	points[id] = point;
}

void Component::PushComponent(std::shared_ptr<Shader> shader, unsigned int id) {
	shaders[id] = shader;
}

std::shared_ptr<Shader> Component::GetComponent(unsigned int id) {
	return shaders.at(id);
}

void Component::Setup(unsigned int id) {
	if (cubes.find(id) != cubes.end())
		cubes.at(id)->Setup();

	if (points.find(id) != points.end())
		points.at(id)->Setup();
}

void Component::DrawCube(unsigned int id) {
	if (cubes.find(id) != cubes.end())
		cubes.at(id)->Draw(shaders.at(id));
}

void Component::DrawLight(unsigned int id) {
	if (points.find(id) != points.end())
		points.at(id)->Draw(shaders.at(id));
}
