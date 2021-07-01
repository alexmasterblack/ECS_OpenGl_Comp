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

void Component::PushComponent(Vec3 position, unsigned int id) {
	positions[id] = position;
}

void Component::PushComponent(Camera camera, unsigned int id) {
	cameras[id] = camera;
}

void Component::PushPointLight(Light point) {
	this->point = point;
}

void Component::PushSpotLight(Light spot) {
	this->spot = spot;
}

void Component::PushFading(Vec3 fading) {
	this->fading = fading;
}

void Component::PushCutOff(float cutOff) {
	this->cutOff = cutOff;
}

void Component::PushOuterCutOff(float outerCutOff) {
	this->outerCutOff = outerCutOff;
}

void Component::PushShininess(float shininess) {
	this->shininess = shininess;
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

void Component::SetLight(unsigned int id, Vec3 positions[]) {
	if (cubes.find(id) != cubes.end()) {
		cubes.at(id)->SetPointLighting(shaders.at(id), positions, fading, cameras.at(id), point, shininess);
		cubes.at(id)->SetSpotLighting(shaders.at(id), fading, cameras.at(id), spot, cutOff, outerCutOff);
	}
	//unsigned int lightId = -1;
	//if (points.find(id) != points.end()) {
	//	lightId = id;
	//}
}

void Component::DrawCube(unsigned int id) {
	if (cubes.find(id) != cubes.end())
		cubes.at(id)->Draw(shaders.at(id), positions.at(id));
}

void Component::DrawLight(unsigned int id) {
	if (points.find(id) != points.end())
		points.at(id)->Draw(shaders.at(id), positions.at(id));
}
