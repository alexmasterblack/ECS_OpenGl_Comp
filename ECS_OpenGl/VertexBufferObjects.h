#pragma once

class VertexBufferObjects {
private:
	unsigned int object;
public:
	VertexBufferObjects() = default;

	VertexBufferObjects(float data[], int size);

	void Binding(int check = -1);
};

