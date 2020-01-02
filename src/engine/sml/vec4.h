//
// Created by User on 2020-01-02.
//



struct vec4 {
    float data[4];
    float& x =data[0], y = data[1], z = data[2],w=data[3];
    vec4();
    vec4(const vec4& other);
    vec4(float x, float y, float z,float w);

    void normalize();
    float dot(const vec4 &other) const;
    vec4 operator*(const vec4 &other) const;

    vec4 operator/(const vec4 &other) const;

    vec4 operator+(const vec4 &other) const;
    void operator+=(const vec4 &other);
    vec4 operator-(const vec4 &other) const;
};


