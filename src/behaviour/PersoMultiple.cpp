#include "PersoMultiple.h"
#include <iostream>

PersoMultiple::PersoMultiple() {}
PersoMultiple::~PersoMultiple() {}

void PersoMultiple::move(Environment & monEnvironment, Bug & b) {
    std::cout << "PersoMultiple is adapting and changing its style!" << std::endl;
}
