#include "Light.h"

Light::Light(Vec3 direction, Vec3 ambient, Vec3 diffuse, Vec3 specular) :
	direction(direction),
	ambient(ambient),
	diffuse(diffuse),
	specular(specular) {}