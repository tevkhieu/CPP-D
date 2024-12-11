#ifndef PERSOMULTIPLE_H
#define PERSOMULTIPLE_H

#include "Behaviour.h"
#include <iostream>

class PersoMultiple : public Behaviour {
public:
    PersoMultiple();
    virtual ~PersoMultiple();
    void move(Environment & monEnvironment, Bug & b) override; // Sobrescribe el método move()
};

#endif // PERSOMULTIPLE_H
