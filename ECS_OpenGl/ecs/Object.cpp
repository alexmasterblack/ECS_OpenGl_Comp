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

void Object::SetComponent(Vec3 position) {
	componets.PushComponent(position, id);
}

std::shared_ptr<Shader> Object::GetShader() {
	return componets.GetComponent(id);
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
