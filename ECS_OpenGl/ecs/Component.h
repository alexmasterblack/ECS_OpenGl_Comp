#ifndef COMPONENT_H
#define COMPONENT_H

#include <map>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../my_math/Vec3.h"
#include "../objects/Cube.h"
#include "../objects/PointLight.h"
#include "../objects/SkyBox.h"
#include "../InputManager.h"
#include "../Shader.h"
#include "../Camera.h"
#include "../Light.h"

class Component {
public:
    Component() = default;

    void PushComponent(std::shared_ptr<Cube> cube, unsigned int id);

    void PushComponent(std::shared_ptr<PointLight> point, unsigned int id);

    void PushComponent(std::shared_ptr<Shader> shader, unsigned int id);

    void PushComponent(std::shared_ptr<SkyBox> skybox, unsigned int id);

    void PushComponent(Vec3 position, unsigned int id);

    void PushComponent(Camera camera, unsigned int id);

    void PushComponent(InputManager input);

    void PushPointLight(Light point);

    void PushSpotLight(Light spot);

    void PushDirectLight(Light directional);

    void PushFading(Vec3 fading);

    void PushCutOff(float cutOff);

    void PushOuterCutOff(float outerCutOff);

    void PushShininess(float shininess);

    void PushEvent(sf::Event event);

    void PushPosition(Vec3 position);

    void PushFront(Vec3 front);

    void PushUp(Vec3 up);

    void PushYaw(float yaw);

    void PushPitch(float pitch);

    void PushMouse(std::pair<int, int> mouse);

    void PushSpeed(float speed);

    void PushSpeedMouse(float speedMouse);

    std::shared_ptr<Shader> GetComponent(unsigned int id);

    void Input(bool& flag);

    void Setup(unsigned int id);

    void SetLight(unsigned int id);

    void DrawCube(unsigned int id);

    void DrawLight(unsigned int id);

    void DrawSkyBox(unsigned int id);
private:
    std::map<unsigned int, std::shared_ptr<PointLight>> points;
    std::map<unsigned int, std::shared_ptr<Shader>> shaders;
    std::map<unsigned int, std::shared_ptr<Cube>> cubes;
    std::map<unsigned int, std::shared_ptr<SkyBox>> skybox;
    std::map<unsigned int, Vec3> positions;
    std::map<unsigned int, Camera> cameras;
    InputManager input;

    Light point;
    Light spot;
    Light directional;
    Vec3 fading;
    float shininess;
    float cutOff;
    float outerCutOff;

    sf::Event event;
    Vec3 position;
    Vec3 front;
    Vec3 up;
    std::pair<int, int> mouse;
    float yaw;
    float pitch;
    float speed;
    float speedMouse;

    std::vector<Vec3> GetLightPos();
    void UpdateCamera();
};

#endif