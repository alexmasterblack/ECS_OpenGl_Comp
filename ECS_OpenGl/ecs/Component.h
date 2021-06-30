#ifndef COMPONENT_H
#define COMPONENT_H

#include <map>
#include <memory>

#include "../objects/Cube.h"
#include "../objects/PointLight.h"
#include "../objects/SkyBox.h"
#include "../Shader.h"
#include "../Camera.h"

class Component {
public:
    Component() = default;

    void PushComponent(std::shared_ptr<Cube> cube, unsigned int id);

    void PushComponent(std::shared_ptr<PointLight> point, unsigned int id);

    void PushComponent(std::shared_ptr<Shader> shader, unsigned int id);

    std::shared_ptr<Shader> GetComponent(unsigned int id);

    void Setup(unsigned int id);

    void DrawCube(unsigned int id);

    void DrawLight(unsigned int id);

    std::map<unsigned int, std::shared_ptr<Cube>> cubes;
private:
    std::map<unsigned int, std::shared_ptr<PointLight>> points;
    std::map<unsigned int, std::shared_ptr<Shader>> shaders;
};

#endif