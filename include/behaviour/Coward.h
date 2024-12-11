#ifndef COWARD_H
#define COWARD_H

#include "Behaviour.h"
#include <iostream>

class Coward : public Behaviour {
public:
    Coward();
    virtual ~Coward();
    void move(Environment & monEnvironment, Bug & b) override; // Sobrescribe el método move()
};

#endif // COWARD_H
