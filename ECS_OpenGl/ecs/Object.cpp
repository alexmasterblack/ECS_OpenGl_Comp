#include "Object.h"

Object::Object() {
	static unsigned int global;
	id = global;
	global++;
}

unsigned int Object::GetId() {
	return id;
}

void Object::SetComponent(std::shared_ptr<Cube> cube) {
	componets.PushComponent(cube, id);
}

void Object::SetComponent(std::shared_ptr<PointLight> point) {
	componets.PushComponent(point, id);
}

void Object::SetComponent(std::shared_ptr<Shader> shader) {
	componets.PushComponent(shader, id);
}

void Object::SetComponent(std::shared_ptr<SkyBox> skybox) {
	componets.PushComponent(skybox, id);
}

void Object::SetComponent(InputManager input) {
	componets.PushComponent(input);
}

void Object::SetComponent(Camera camera) {
	componets.PushComponent(camera, id);
}

void Object::SetPointLight(Light point) {
	componets.PushPointLight(point);
}

void Object::SetSpotLight(Light spot) {
	componets.PushSpotLight(spot);
}

void Object::SetDirectLight(Light directional) {
	componets.PushDirectLight(directional);
}

void Object::SetEvent(sf::Event event) {
	componets.PushEvent(event);
}

void Object::SetFading(float constant, float linear, float quadratic) {
	componets.PushFading(Vec3(constant, linear, quadratic));
}

void Object::SetFading(Vec3 fading) {
	componets.PushFading(fading);
}

void Object::SetCutOff(float cutOff) {
	componets.PushCutOff(cutOff);
}

void Object::SetOuterCutOff(float outerCutOff) {
	componets.PushOuterCutOff(outerCutOff);
}

void Object::SetShininess(float shininess) {
	componets.PushShininess(shininess);
}

void Object::SetCamPos(Vec3 position) {
	componets.PushPosition(position);
}

void Object::SetCamFront(Vec3 front) {
	componets.PushFront(front);
}

void Object::SetCamUp(Vec3 up) {
	componets.PushUp(up);
}

void Object::SetCamYaw(float yaw) {
	componets.PushYaw(yaw);
}

void Object::SetCamPitch(float pitch) {
	componets.PushPitch(pitch);
}

void Object::SetMouse(std::pair<int, int> mouse) {
	componets.PushMouse(mouse);
}

void Object::SetSpeed(float speed) {
	componets.PushSpeed(speed);
}

void Object::SetSpeedMouse(float speedMouse) {
	componets.PushSpeedMouse(speedMouse);
}

void Object::SetComponent(Vec3 position) {
	componets.PushComponent(position, id);
}

std::shared_ptr<Shader> Object::GetShader() {
	return componets.GetComponent(id);
}

void Object::ReadInput(bool& flag) {
	componets.Input(flag);
}

void Object::SetLight() {
	componets.SetLight(id);
}

void Object::Setup() {
	componets.Setup(id);
}

void Object::Draw() {
	componets.DrawCube(id);
}

void Object::DrawLight() {
	componets.DrawLight(id);
}

void Object::DrawSkyBox() {
	componets.DrawSkyBox(id);
}
