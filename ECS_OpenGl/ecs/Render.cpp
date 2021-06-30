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

void Render::SetLighting(Shader& shader, Camera& camera, Vec3 positionsPoint[]) {
	shader.Use();
	shader.SetVec3("viewPos", camera.GetPosition());
	shader.SetFloat("material.shininess", 32.0f);

	Light dirLight(Vec3(-0.2f, -1.0f, -0.3f), Vec3(0.05f, 0.05f, 0.05f), Vec3(0.4f, 0.4f, 0.4f), Vec3(0.5f, 0.5f, 0.5f));
	shader.SetVec3("dirLight.direction", dirLight.direction);
	shader.SetVec3("dirLight.ambient", dirLight.ambient);
	shader.SetVec3("dirLight.diffuse", dirLight.diffuse);
	shader.SetVec3("dirLight.specular", dirLight.specular);

	for (int i = 0; i < 3; i++) {
		shader.SetVec3("pointLights[" + std::to_string(i) + "].position", positionsPoint[i]);
		shader.SetVec3("pointLights[" + std::to_string(i) + "].ambient", Vec3(0.05f, 0.05f, 0.05f));
		shader.SetVec3("pointLights[" + std::to_string(i) + "].diffuse", Vec3(0.8f, 0.8f, 0.8f));
		shader.SetVec3("pointLights[" + std::to_string(i) + "].specular", Vec3(1.0f, 1.0f, 1.0f));
		shader.SetFloat("pointLights[" + std::to_string(i) + "].constant", 1.0f);
		shader.SetFloat("pointLights[" + std::to_string(i) + "].linear", 0.09);
		shader.SetFloat("pointLights[" + std::to_string(i) + "].quadratic", 0.032);
	}

	shader.SetVec3("spotLight.position", camera.GetPosition());
	shader.SetVec3("spotLight.direction", camera.GetFront());
	shader.SetVec3("spotLight.ambient", Vec3(0.0f, 0.0f, 0.0f));
	shader.SetVec3("spotLight.diffuse", Vec3(1.0f, 1.0f, 1.0f));
	shader.SetVec3("spotLight.specular", Vec3(1.0f, 1.0f, 1.0f));
	shader.SetFloat("spotLight.constant", 1.0f);
	shader.SetFloat("spotLight.linear", 0.09);
	shader.SetFloat("spotLight.quadratic", 0.032);
	shader.SetFloat("spotLight.cutOff", glm::cos(glm::radians(12.0f)));
	shader.SetFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
}
