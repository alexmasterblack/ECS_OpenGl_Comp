#include "VertexBufferObjects.h"
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

VertexBufferObjects::VertexBufferObjects(float data[], int size)
{
	glGenBuffers(1, &object);
	glBindBuffer(GL_ARRAY_BUFFER, object);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(data), data, GL_STATIC_DRAW);
}

void VertexBufferObjects::Binding(int check)
{
	if (check == 0)
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	else
		glBindBuffer(GL_ARRAY_BUFFER, object);
}