#ifndef INPUT_H
#define INPUT_H

#include <utility>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "my_math/Vec3.h"

class InputManager {
public:
	InputManager() = default;

	void ReadInput(sf::Event event,
		std::pair<int, int>& mouse,
		Vec3& position,
		Vec3& front,
		Vec3& up,
		float& yaw,
		float& pitch,
		float& speed,
		float& speedMouse,
		bool& flag);
};

#endif