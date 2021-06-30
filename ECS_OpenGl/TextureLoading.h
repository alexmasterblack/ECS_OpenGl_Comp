#ifndef TEXTURE_H
#define TEXTURE_H

#include <vector>
#include <string>

#include<iostream>
#include <GL/glew.h>
#include "general/stb_image.h"

class TextureLoading {
private:
	unsigned int texture;
public:
	TextureLoading() = default;

	TextureLoading& operator=(const TextureLoading& other);

	TextureLoading(std::vector<std::string> texture_faces);

	TextureLoading(const char* path);

	void Binding(int check = -1);

	unsigned int GetTexture();
};

#endif