#ifndef GREGARIOUS_H
#define GREGARIOUS_H

#include "Behaviour.h"
#include <iostream>

class Gregarious : public Behaviour {
public:
    Gregarious();
    virtual ~Gregarious();
    void move(Environment & monEnvironment, Bug & b) override; // Sobrescribe el método move()
};

#endif // GREGARIOUS_H
