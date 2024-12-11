#ifndef _BUGSPECIESFACTORY_H_
#define _BUGSPECIESFACTORY_H_

#include "BugFactory.h"
#include "BugSpecies.h"

class BugSpeciesFactory: public BugFactory {
public:
    BugSpeciesFactory();
    ~BugSpeciesFactory() override;
    BugSpecies* birth();
    BugSpecies* clone(const Bug & b);

};


#endif