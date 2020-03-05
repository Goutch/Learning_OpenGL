#pragma once

#include <string>
class Entity {
    std::string name;
public:
    void setName(const std::string &name);

public:
    virtual ~Entity();

    const std::string &getName() const;
};
