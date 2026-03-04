#pragma once

#include "Cleric.h"
#include "Sorcerer.h"

class Multiclass :
    public Cleric, public Sorcerer
{
public:
    Multiclass();
    Multiclass(std::string _name, std::string _deity, int _numSpells);
    ~Multiclass();

    void PrintData() override;
    void PrintType() override;
};

