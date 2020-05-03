//
// Created by User on 2020-01-18.
//
#include "SpacialSceneDemo.h"
#include "API_ALL.h"
#include "Grass.h"

void createRainbowTexture(Texture &texture) {
    std::vector<unsigned char> data;
    data.resize(1024 * 1024 * 3);
    const float PI = 3.1416;

    for (int x = 0; x < 1024; ++x) {
        for (int y = 0; y < 1024; ++y) {
            vec2 uv((float)x/1024.0f,(float)y/1024.0f);
            uv-=0.5;
            int index = ((1024 * x) + y) * 3;

            float ratio = distance(uv,vec2(0,0));
            ratio*=2;
            double r, g, b;


            r =(cos(ratio * PI * 2.) + 1)/2;
            g =  (cos((ratio + 0.33333) * PI * 2.) + 1)/2 ;
            b = (cos((ratio + 0.66666) * PI * 2.) + 1)/2;

            data[index] = static_cast<unsigned char>(r * 255);
            data[index + 1] =static_cast<unsigned char>(g * 255);
            data[index + 2] =static_cast<unsigned char> (b * 255);
        }
    }
    texture.setTexturePixelData(data.data(), 1024, 1024, true, Texture::Type::RGB);
}

void SpacialSceneDemo::init(Canvas &canvas, Renderer &renderer, Input &input) {
    Scene::init(canvas, renderer, input);
   // renderer.setSkyboxTexture(skybox_texture);
    ambient_light = Color(0.2, 0.2, 0.2, 1);
    input.showCursor(false);
    //create cube_mesh mesh
    Geometry::make_cube(cube_mesh);


    //ground
    instantiate(new MeshRenderer(cube_mesh, ground_material, vec3(0, -.5, 0), vec3(0), vec3(1000, 1, 1000)));
    //sphere
        Geometry::make_sphere(sphere_mesh,2,100,100);
    sphere_material.normalMap(&earth_normal_map);
    sphere_material.shine(20);
    sphere_material.damp(16);
    Entity* sphere=new MeshRenderer(sphere_mesh, sphere_material, vec3(0, 5, 0));
    sphere->transform.rotate(quat(vec3(3.1616/2,0,0)));
    instantiate(sphere);
    //bunnies
    createRainbowTexture(rainbow_texture);
    rainbow_material.damp(16);
    rainbow_material.shine(64);
    instantiate(new MeshRenderer(bunny_mesh, rainbow_material, vec3(10, 0, 0),vec3(0),vec3(5,5,5)));
    instantiate(new MeshRenderer(bunny_mesh, bunny_material, vec3(-10, 0, 0),vec3(0),vec3(5,5,5)));

    //dragons
    dragon_material.shine(20);
    dragon_material.damp(16);
    dragon_material.setColor(Color(0.7, 0.4, 0.4));
    instantiate(new MeshRenderer(dragon_mesh, dragon_material, vec3(0, 0, -10)));
     instantiate(new MeshRenderer(dragon_mesh, dragon_material, vec3(0, 0, 10)));
    //duck
    instantiate(new MeshRenderer(duck_mesh,duck_material,vec3(14,0,14)));
    //controller
    instantiate(new FPSController(*camera, vec3(0, 2, 2), vec3(0), vec3(1)));

    Entity* e=new PointLight(Color(1,1,1),50,vec3(0,5,0));
    e->setParent(camera);
    instantiate(e);
    //Directional sun light
   sun = new DirectionalLight(Color(1, 1, 1), vec3(0, 2, 0), glm::radians(vec3(-45, -45, 0)));

    instantiate(sun);
}

void SpacialSceneDemo::update(float delta) {
    Scene::update(delta);
    if (input->isKeyDown(GLFW_KEY_4)) {
        canvas->setShader(blur_shader);
    }
    if (input->isKeyDown(GLFW_KEY_3)) {
        canvas->setShader(negative_shader);
    }
    if (input->isKeyDown(GLFW_KEY_2)) {
        canvas->setShader(edge_shader);
    }
    if (input->isKeyDown(GLFW_KEY_1)) {
        canvas->setShader(renderer->DEFAULT_2D_SHADER);
    }

    edge_shader.bind();
    edge_shader.loadUniform("resolution", vec2(canvas->getPixelWidth(), canvas->getPixelHeight()));
    edge_shader.unbind();

}

void SpacialSceneDemo::render() const {
    Scene::render();

}

void SpacialSceneDemo::draw() const {
    Scene::draw();
}

SpacialSceneDemo::~SpacialSceneDemo() {
}
