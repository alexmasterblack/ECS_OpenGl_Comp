#include "Shader.h"

Shader& Shader::operator=(const Shader& other) {
	shaderProgram = other.shaderProgram;
	return *this;
}

Shader::Shader(std::string vertexPath, std::string fragmentPath) {
	shaderProgram = LoadShaders(vertexPath, fragmentPath);
}

void Shader::SetMat4(std::string id, const Mat4& data) {
	glm::mat4 matrix = TrueView(data);
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, id.c_str()), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::SetVec3(const std::string id, const Vec3& data) {
	glm::vec3 true_view = glm::vec3(data.x, data.y, data.z);
	glUniform3fv(glGetUniformLocation(shaderProgram, id.c_str()), 1, &true_view[0]);
}

void Shader::SetInt(const std::string id, int data) {
	glUniform1i(glGetUniformLocation(shaderProgram, id.c_str()), data);
}

void Shader::SetFloat(const std::string id, float data) {
	glUniform1f(glGetUniformLocation(shaderProgram, id.c_str()), data);
}

void Shader::Use() {
	glUseProgram(shaderProgram);
}

unsigned int Shader::GetId() {
	return shaderProgram;
}

glm::mat4 Shader::TrueView(const Mat4& data)
{
	return glm::mat4(
		data.data[0][0], data.data[0][1], data.data[0][2], data.data[0][3],
		data.data[1][0], data.data[1][1], data.data[1][2], data.data[1][3],
		data.data[2][0], data.data[2][1], data.data[2][2], data.data[2][3],
		data.data[3][0], data.data[3][1], data.data[3][2], data.data[3][3]);
}
