#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_


#include "UImg.h"
#include "Bug.h"
#include "BugSpeciesFactory.h"
#include <iostream>
#include <vector>

using namespace std;


class Environment : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Bug*>   listePBugs;
   float birthRate, cloneRate;
   float angularVisionMin, angularVisionMax;
   float visionDisanceMin, visionDistanceMax;
   float hearingDistanceMin, hearingDistanceMax;
   float kamikazeRate, cowardRate, gregariousRate, foreseeingRate, persoMultipleRate;
   float shellRate, finRate, eyesRate, earsRate;
   float collisionDeathRate;
   float exteriorEventRate;
   int epoch;

   BugSpeciesFactory *pFactory;


public :
   Environment( int _width, int _height );
   ~Environment( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( const Bug & b ) { listeBugs.push_back(b); listeBugs.back().initCoords(width, height); }
   int nbNeighbours( const Bug & b );
   Bug* closestNeighbour (const Bug & b);

   void init();
   void createInitialPopulation();
   void checkCollisions();
   void bugAct();
   void drawBugs();
   void cloneBugs();

   int getEpoch() const { return epoch; }

};

#endif
