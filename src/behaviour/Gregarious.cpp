#include "Gregarious.h"
#include <iostream>

Gregarious::Gregarious() {}
Gregarious::~Gregarious() {}
void Gregarious::move(Environment & monEnvironment, Bug & b) {
    std::cout << "Gregarious is moving in groups!" << std::endl;
}
