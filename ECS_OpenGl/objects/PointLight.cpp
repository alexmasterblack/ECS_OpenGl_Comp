#include "PointLight.h"

void PointLight::Setup() {
	VAO.Binding();
	VAO.VertexAttribPointer(0, 3, 8 * sizeof(float), (void*)0);
}

void PointLight::Draw(std::shared_ptr<Shader> shader, Vec3 position) {
	VAO.Binding();

	Mat4 model(1.0f);
	model = model.Translate(position);
	model = model.Scale(Vec3(0.3f));
	shader->SetMat4("model", model);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
