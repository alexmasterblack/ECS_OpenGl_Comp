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

void Object::SetComponent(Vec3 position) {
	componets.PushComponent(position, id);
}

std::shared_ptr<Shader> Object::GetShader() {
	return componets.GetComponent(id);
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
