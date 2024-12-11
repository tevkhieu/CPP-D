#ifndef BEHAVIOR_H
#define BEHAVIOR_H

class Bug;
class Environment;

class Behaviour {
public:
    virtual void move(Environment & monEnvironment, Bug & b) = 0; // Método virtual puro
    virtual ~Behaviour() = default; // Destructor virtual para herencia segura
};

#endif 
