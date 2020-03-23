#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <array>
#include <iostream>
using namespace glm;
struct Plane{
    //x,y,z is the normal vector
    //w is the distance from the origin
    vec4 equation;
    vec3 normal;
    float d;
    void set(vec4 equation){
        this->equation=equation;
        this->normal=vec3(equation.x,equation.y,equation.z);

    }
    //point is in world space
    float distance(vec3 point) const{
        return (normal.x * point.x) + (normal.y * point.y) + (normal.z * point.z)+d;
    };
};
float width=900;
float height=600;
float aspect=width/height;
float fov=90;
float far_dist=100;
float near_dist=0.1;
mat4 view_mat=glm::inverse(mat4(1.0f));
mat4 projection_mat = glm::perspective(fov, aspect, near_dist, far_dist)*view_mat;
mat4 m=projection_mat*view_mat;

std::array<Plane, 6> planes;
std::array<std::string,6> planes_names={"left","right","bottom","top","near","far"};

void printPlanesData()
{
    for (int i = 0; i < planes.size(); ++i) {

        std::cout<<'\n'<<(std::to_string(i))<<" "<<planes_names[i]<<std::endl;

        std::cout<<("equation:" + std::to_string(planes[i].equation.x) + "a+" + std::to_string(planes[i].equation.y) + "b+" +
        std::to_string(planes[i].equation.z) + "c=" + std::to_string(planes[i].equation.w))<<std::endl;

        std::cout<<("normal:(" + std::to_string(planes[i].normal.x) + "," + std::to_string(planes[i].normal.y) + "," +
        std::to_string(planes[i].normal.z) + ")")<<std::endl;

        std::cout<<("distance:" + std::to_string(planes[i].d))<<std::endl;
    }
}
void testPointInsideFrustum(vec3 point){
    std::cout<<'\n'<<std::endl;
    bool inside = true;
    for (int i = 0; i < planes.size(); i++) {
        float d=planes[i].distance(point);
        std::cout<<("distance "+planes_names[i]+":"+std::to_string(d))<<std::endl;
        if ( 0>d) {
            inside = false;
        }
    }
    std::cout<< "("+std::to_string(point.x) + "," + std::to_string(point.y) + "," +
                std::to_string(point.z) + "):" + std::string(inside ? "inside" : "outside")<<std::endl;
}
int main() {
    planes[0].set(m[3] + m[0]);//left
    planes[1].set(m[3] - m[0]);//right
    planes[3].set(m[3] + m[1]);//bottom
    planes[2].set(m[3] - m[1]);//top
    planes[4].set(m[3] + m[2]);//near
    planes[5].set(m[3] - m[2]);//far
    printPlanesData();
    testPointInsideFrustum(vec3(0,0,-5));//inside
    testPointInsideFrustum(vec3(0,0,5));//outside
    testPointInsideFrustum(vec3(0,0,-99));//inside
    testPointInsideFrustum(vec3(0,0,99));//outside
    return 0;
}
