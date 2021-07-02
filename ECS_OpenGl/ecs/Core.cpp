#include "Core.h"

Core::Core(sf::ContextSettings windows_settings) :
	window(sf::VideoMode(800, 600, 32), "ECS_OpenglGl", sf::Style::Titlebar | sf::Style::Close, windows_settings) {
	Init();
	scene.Setup();
	while (flag) {
		InputEvent();
		Update();
		PostUpdate();
		window.display();
	}
	window.close();
}

void Core::Init() {
	window.setMouseCursorVisible(false);
	window.setMouseCursorGrabbed(true);
	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit()) {
		std::cout << "Error:: glew not init =(" << std::endl;
		exit(-1);
	}
	glEnable(GL_DEPTH_TEST);
}

void Core::InputEvent() {
	sf::Event event;
	while (window.pollEvent(event)) {
		scene.Event(event, flag);
	}
}

void Core::Update() {
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	scene.Lighting();
}

void Core::PostUpdate() {
	scene.Draw();
}
