

#include "Renderer.h"

#define GLEW_STATIC

#include "GL/glew.h"


#include <Core/Canvas.h>


const int Renderer::PRIMITIVE_TRIANGLES = GL_TRIANGLES;
const int Renderer::PRIMITIVE_POINTS = GL_POINTS;

Renderer::Renderer() {
    depthShader_light_space_matrix_location = DEPTH_SHADER.uniformLocation("space");
    depthShader_transform_mat_location = DEPTH_SHADER.uniformLocation("transform");
    glClearColor(0.4, 0.4, 0.7, 1);

}

void Renderer::clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearDepth() const {
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearColor() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::renderOnMainBuffer(const Canvas &canvas) {
    glDisable(GL_DEPTH_TEST);
    canvas.getMaterial().bind();
    canvas.getVAO().bind();
    canvas.getMaterial().transform(canvas.transform.getMatrix());
    canvas.getMaterial().projection(canvas.getPixelProjection());
    glDrawElements(GL_TRIANGLES, canvas.getVAO().getVertexCount(), GL_UNSIGNED_INT, nullptr);
    canvas.getVAO().unbind();
    canvas.getMaterial().unbind();
}

void Renderer::wireframe(bool enable) {
    enable ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

#include <stb_image_write.h>
#include <Utils/TimeUtils.h>

void Renderer::screenShot(int width, int height) {
    unsigned char* pixel_data = new unsigned char[4*width*height];
    glReadBuffer(GL_FRONT);
    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixel_data);
    stbi_write_png(std::string("../screenshot/"+TimeUtils::getTimeString()+".png").c_str(),width,height,4,pixel_data,0);
    delete[] pixel_data;
}

void Renderer::setSkyboxTexture(AtlasTexture& texture) {
    if(skybox)delete skybox;
    skybox=new Skybox(texture,DEFAULT_SPACIAL_SHADER);
}



















