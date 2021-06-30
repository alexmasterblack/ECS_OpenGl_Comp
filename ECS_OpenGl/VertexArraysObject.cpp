#include "VertexArraysObject.h"

VertexArraysObject::VertexArraysObject()
{
	glGenVertexArrays(1, &object);
}

void VertexArraysObject::VertexAttribPointer(GLuint index, GLint size, GLsizei stride, const void* pointer)
{
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, pointer);
	glEnableVertexAttribArray(index);
}

void VertexArraysObject::Binding(int check)
{
	if (check == 0)
		glBindVertexArray(0);
	else
		glBindVertexArray(object);
}
