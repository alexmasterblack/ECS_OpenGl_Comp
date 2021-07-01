#include "Core.h"

Core::Core(sf::ContextSettings windows_settings) :
	window(sf::VideoMode(800, 600, 32), "ECS_OpenglGl", sf::Style::Titlebar | sf::Style::Close, windows_settings) {
	Init();
	scene.Setup();
	bool isGo = true;
	while (isGo) {
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

void Core::InputEvent()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				camera.SetPosition(camera.GetPosition() + (camera.GetFront() * camera.GetSpeed()));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				camera.SetPosition(camera.GetPosition() - (camera.GetRight() * camera.GetSpeed()));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				camera.SetPosition(camera.GetPosition() + (camera.GetRight() * camera.GetSpeed()));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				camera.SetPosition(camera.GetPosition() - (camera.GetFront() * camera.GetSpeed()));
			}
			break;
		case sf::Event::MouseMoved:
			float xOffset = sf::Mouse::getPosition(window).x - camera.GetPos().first;
			float yOffset = camera.GetPos().second - sf::Mouse::getPosition(window).y;

			camera.SetPos(std::pair<float, float>(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));

			camera.SetYaw(camera.GetYaw() + (xOffset * 0.3f));
			camera.SetPitch(camera.GetPitch() + (yOffset * 0.3f));

			camera.UpdateCameraVectors();
			break;
		} 
	}
}

void Core::Update() {
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	scene.Lighting(camera);
}

void Core::PostUpdate() {
	scene.Draw();
}
