#pragma once
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class VertexArraysObject {
private:
	unsigned int object;
public:
	VertexArraysObject();

	void VertexAttribPointer(GLuint index, GLint size,  GLsizei stride, const void* pointer);

	void Binding(int check = -1);
};

