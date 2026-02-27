#pragma once

#include "Pet.h"

class Dog :
    public Pet
{
public:
    Dog(std::string _name);
    void talk() override;
private:
    unsigned short volume;
};

