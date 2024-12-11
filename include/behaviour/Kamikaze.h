#ifndef KAMIKAZE_H
#define KAMIKAZE_H

#include "Behaviour.h"
#include <iostream>
#include <cstdlib>
#include <cmath>


class Kamikaze : public Behaviour {
public:
    Kamikaze();
    virtual ~Kamikaze();
    void move(Environment & monEnvironment, Bug & b) override;
};

#endif // KAMIKAZE_H
