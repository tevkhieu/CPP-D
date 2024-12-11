#ifndef _BUGFACTORY_H
#define _BUGFACTORY_H

#include "BugSpeciesFactory.h"

class BugFactory {
public:
    BugFactory();
    virtual ~BugFactory();
    virtual Bug* birth() = 0;
    virtual Bug* clone(const Bug & b) = 0;
    

};

#endif
