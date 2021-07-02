#ifndef CORE_H
#define CORE_H

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Scene.h"

class Core {
public:
	Core() = default;

	Core(sf::ContextSettings windows_settings);

	void Init();

	void InputEvent();

	void Update();

	void PostUpdate();
private:
	sf::RenderWindow window;
	Scene scene;
	bool flag = true;
};

#endif