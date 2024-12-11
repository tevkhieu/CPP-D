#ifndef _BUGSPECIESFACTORY_H_
#define _BUGSPECIESFACTORY_H_

#include "BugFactory.h"
#include "Behaviour.h"
#include "BugSpecies.h"

/*Default creation method for bugspecies birth*/
BugSpecies BugSpeciesFactory::birth(Behaviour *behaviour) {
    BugSpecies *bugSpecies = new BugSpecies();
    bugSpecies->setBehaviour(&behaviour);

    return bugSpecies;
}

/*Clone creation method for bugspecies*/
BugSpecies BugSpeciesFactory::clone(const BugSpecies & b) {
    BugSpecies *bugSpecies = new BugSpecies(b);
    bugSpecies->setBehaviour(b.getBehaviour());

    return bugSpecies;
}

#endif