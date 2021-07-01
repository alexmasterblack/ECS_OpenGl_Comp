#ifndef COMPONENT_H
#define COMPONENT_H

#include <map>
#include <memory>

#include "../my_math/Vec3.h"

#include "../objects/Cube.h"
#include "../objects/PointLight.h"
#include "../objects/SkyBox.h"
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

    void PushPointLight(Light point);

    void PushSpotLight(Light spot);

    void PushDirectLight(Light directional);

    void PushFading(Vec3 fading);

    void PushCutOff(float cutOff);

    void PushOuterCutOff(float outerCutOff);

    void PushShininess(float shininess);

    std::shared_ptr<Shader> GetComponent(unsigned int id);

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

    Light point;
    Light spot;
    Light directional;
    Vec3 fading;
    float shininess;
    float cutOff;
    float outerCutOff;

    std::vector<Vec3> GetLightPos();
};

#endif