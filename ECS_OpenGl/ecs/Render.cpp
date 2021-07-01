#include "Render.h"

Render::Render(std::vector<Object> objects) {
	this->objects = objects;
}

void Render::Draw() {
	for (int count = 0; count < objects.size(); count++) {
		objects[count].Draw();
	}

	for (int count = 0; count < objects.size(); count++) {
		objects[count].DrawLight();
	}

	for (int count = 0; count < objects.size(); count++) {
		objects[count].DrawSkyBox();
	}
}

void Render::SetLighting() {
	for (int count = 0; count < objects.size(); count++) {
		objects[count].SetLight();
	}
}
