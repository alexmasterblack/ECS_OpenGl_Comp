#include "Render.h"

void Render::DrawCube(std::vector<Object> objects) {
	for (int count = 0; count < objects.size(); count++) {
		objects[count].Draw();
	}
}

void Render::DrawPoint(std::vector<Object> objects) {
	for (int count = 0; count < objects.size(); count++) {
		objects[count].DrawLight();
	}
}

void Render::DrawSkyBox(Shader& shader, Camera& camera, std::shared_ptr<SkyBox> skybox) {
	Mat4 view(camera.GetViewMatrix());
	Mat4 projection(camera.GetProjectionMatrix());

	glDepthFunc(GL_LEQUAL);
	shader.Use();
	view = camera.GetViewSkyBox();
	shader.SetMat4("view", view);
	shader.SetMat4("projection", projection);
	skybox->Draw();
	glDepthFunc(GL_LESS);
}

void Render::SetLighting(std::vector<Object> objects) {
	for (int count = 0; count < objects.size(); count++) {
		objects[count].SetLight();
	}
}
