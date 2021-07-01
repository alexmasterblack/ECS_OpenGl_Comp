#include "Cube.h"

float ToRadians(float number) {
	return number * static_cast<float>(0.01745329251994329576923690768489);
}

void Cube::Setup() {
	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	VertexBufferObjects VBO(vertices, sizeof(vertices) / sizeof(float));
	VBO.Binding();

	VAO.Binding();
	VAO.VertexAttribPointer(0, 3, 8 * sizeof(float), (void*)0);
	VAO.VertexAttribPointer(1, 3, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO.VertexAttribPointer(2, 2, 8 * sizeof(float), (void*)(6 * sizeof(float)));
}

void Cube::SetLight(
	std::shared_ptr<Shader> shader, 
	std::vector<Vec3> positions, 
	Vec3 fading, 
	Camera camera, 
	Light point, 
	Light spot, 
	Light directional,
	float shininess,
	float cutOff,
	float outerCutOff) {
	shader->Use();
	shader->SetVec3("viewPos", camera.GetPosition());
	shader->SetFloat("material.shininess", shininess);

	shader->SetVec3("dirLight.direction", directional.direction);
	shader->SetVec3("dirLight.ambient", directional.ambient);
	shader->SetVec3("dirLight.diffuse", directional.diffuse);
	shader->SetVec3("dirLight.specular", directional.specular);

	for (int i = 0; i < 3; i++) {
		shader->SetVec3("pointLights[" + std::to_string(i) + "].position", positions[i]);
		shader->SetVec3("pointLights[" + std::to_string(i) + "].ambient", point.ambient);
		shader->SetVec3("pointLights[" + std::to_string(i) + "].diffuse", point.diffuse);
		shader->SetVec3("pointLights[" + std::to_string(i) + "].specular", point.specular);
		shader->SetFloat("pointLights[" + std::to_string(i) + "].constant", fading.x);
		shader->SetFloat("pointLights[" + std::to_string(i) + "].linear", fading.y);
		shader->SetFloat("pointLights[" + std::to_string(i) + "].quadratic", fading.z);
	}

	shader->SetVec3("spotLight.position", camera.GetPosition());
	shader->SetVec3("spotLight.direction", camera.GetFront());
	shader->SetVec3("spotLight.ambient", spot.ambient);
	shader->SetVec3("spotLight.diffuse", spot.diffuse);
	shader->SetVec3("spotLight.specular", spot.specular);
	shader->SetFloat("spotLight.constant", fading.x);
	shader->SetFloat("spotLight.linear", fading.y);
	shader->SetFloat("spotLight.quadratic", fading.z);
	shader->SetFloat("spotLight.cutOff", cos(ToRadians(cutOff)));
	shader->SetFloat("spotLight.outerCutOff",cos(ToRadians(outerCutOff)));
}

void Cube::Draw(std::shared_ptr<Shader> shader, Vec3 position, Camera camera) {
	Mat4 view(camera.GetViewMatrix());
	Mat4 projection(camera.GetProjectionMatrix());

	shader->Use();
	shader->SetMat4("view", view);
	shader->SetMat4("projection", projection);

	VAO.Binding();
	Mat4 model(1.0f);
	model = model.Translate(position);
	shader->SetMat4("model", model);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
