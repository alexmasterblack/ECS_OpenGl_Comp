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

void Component::PushComponent(std::shared_ptr<SkyBox> skybox, unsigned int id) {
	this->skybox[id] = skybox;
}

void Component::PushComponent(InputManager input) {
	this->input = input;
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

void Component::PushDirectLight(Light directional) {
	this->directional = directional;
}

void Component::PushEvent(sf::Event event) {
	this->event = event;
}

void Component::PushPosition(Vec3 position) {
	this->position = position;
}

void Component::PushFront(Vec3 front) {
	this->front = front;
}

void Component::PushUp(Vec3 up) {
	this->up = up;
}

void Component::PushYaw(float yaw) {
	this->yaw = yaw;
}

void Component::PushPitch(float pitch) {
	this->pitch = pitch;
}

void Component::PushMouse(std::pair<int, int> mouse) {
	this->mouse = mouse;
}

void Component::PushSpeed(float speed) {
	this->speed = speed;
}

void Component::PushSpeedMouse(float speedMouse) {
	this->speedMouse = speedMouse;
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

void Component::Input(bool& flag) {
	input.ReadInput(event, mouse, position, front, up, yaw, pitch, speed, speedMouse, flag);
	UpdateCamera();
}

void Component::Setup(unsigned int id) {
	if (cameras.find(id) != cameras.end())
		cameras.at(id).Update(position, front, up);

	if (cubes.find(id) != cubes.end())
		cubes.at(id)->Setup();

	if (points.find(id) != points.end())
		points.at(id)->Setup();

	if (skybox.find(id) != skybox.end())
		skybox.at(id)->Setup(shaders.at(id));
}

void Component::SetLight(unsigned int id) {
	if (cubes.find(id) != cubes.end()) {
		cubes.at(id)->SetLight(shaders.at(id), GetLightPos(), fading, cameras.at(id), point, spot, directional, shininess, cutOff, outerCutOff);
	}
}

void Component::DrawCube(unsigned int id) {
	if (cubes.find(id) != cubes.end())
		cubes.at(id)->Draw(shaders.at(id), positions.at(id), cameras.at(id));
}

void Component::DrawLight(unsigned int id) {
	if (points.find(id) != points.end())
		points.at(id)->Draw(shaders.at(id), positions.at(id), cameras.at(id));
}

void Component::DrawSkyBox(unsigned int id) {
	if (skybox.find(id) != skybox.end())
		skybox.at(id)->Draw(shaders.at(id), cameras.at(id));
}

std::vector<Vec3> Component::GetLightPos() {
	std::vector<Vec3> posLights;
	for (auto const& element : points) {
		posLights.push_back(positions.at(element.first));
	}
	return posLights;
}

void Component::UpdateCamera() {
	for (auto it = cameras.begin(); it != cameras.end(); it++)
		it->second.Update(position, front, up);
}
