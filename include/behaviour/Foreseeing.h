#ifndef FORESEEING_H
#define FORESEEING_H

#include "Behaviour.h"
#include <iostream>

class Foreseeing : public Behaviour {
public:
    Foreseeing();
    virtual ~Foreseeing();
    void move(Environment & monEnvironment, Bug & b) override; // Sobrescribe el método move()
};

#endif // FORESEEING_H
