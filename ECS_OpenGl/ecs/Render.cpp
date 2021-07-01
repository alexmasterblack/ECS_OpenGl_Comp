#include "Render.h"


void Render::DrawCube(Shader& shader, Camera& camera, std::vector<Object> objects) {
	Mat4 view(camera.GetViewMatrix());
	Mat4 projection(camera.GetProjectionMatrix());
	shader.Use();
	shader.SetMat4("view", view);
	shader.SetMat4("projection", projection);
	for (int count = 0; count < objects.size(); count++) {
		objects[count].Draw();
	}
}

void Render::DrawPoint(Shader& shader, Camera& camera, std::vector<Object> objects) {
	Mat4 view(camera.GetViewMatrix());
	Mat4 projection(camera.GetProjectionMatrix());

	shader.Use();
	shader.SetMat4("view", view);
	shader.SetMat4("projection", projection);
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

void Render::SetLighting(std::vector<Object> objects, Vec3 positionsPoint[]) {
	for (int count = 0; count < objects.size(); count++) {
		objects[count].SetLight(positionsPoint);
	}
}
