#ifndef LIGHT_H
#define LIGHT_H

#include "my_math/Vec3.h"

class Light {
public:
	Vec3 direction;
	Vec3 ambient;
	Vec3 diffuse;
	Vec3 specular;

	Light() = default;

	Light(Vec3 direction, Vec3 ambient, Vec3 diffuse, Vec3 specular);
};

#endif