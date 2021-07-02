#include "InputManager.h"

float Radians(float number) {
	return number * static_cast<float>(0.01745329251994329576923690768489);
}

void InputManager::ReadInput(sf::Event event,
	std::pair<int, int>& mouse,
	Vec3& position, 
	Vec3& front, 
	Vec3& up, 
	float& yaw, 
	float& pitch,
	float& speed,
	float& speedMouse,
	bool& flag) {
	switch (event.type) {
	case sf::Event::Closed:
		flag = false;
		break;
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			position += front * speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			Vec3 crossResult(front.CrossProduct(up));
			position -= crossResult.Normalize() * speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			Vec3 crossResult(front.CrossProduct(up));
			position += crossResult.Normalize() * speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			position -= front * speed;
		}
		break;
	case sf::Event::MouseMoved:
		float xOffset = event.mouseMove.x - mouse.first;
		float yOffset = mouse.second - event.mouseMove.y;
		mouse.first = event.mouseMove.x;
		mouse.second = event.mouseMove.y;

		yaw += (xOffset * speedMouse);
		pitch += (yOffset * speedMouse);

		Vec3 vec;
		vec.x = cos(Radians(yaw)) * cos(Radians(pitch));
		vec.y = sin(Radians(pitch));
		vec.z = sin(Radians(yaw)) * cos(Radians(pitch));
		front = vec.Normalize();
		break;
	}
}
