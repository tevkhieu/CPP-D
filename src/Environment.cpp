#include "Environment.h"

#include <cstdlib>
#include <ctime>


const T    Environment::white[] = { (T)255, (T)255, (T)255 };


Environment::Environment( int _width, int _height ) : UImg( _width, _height, 1, 3 ), width(_width), height(_height) {

   cout << "const Environment" << endl;

   std::srand( time(NULL) );

}

void Environment::addMember(const Bug &b) {
    listeBugs.push_back(std::make_unique<Bug>(b));
    listeBugs.back()->initCoords(width, height);
}


Environment::~Environment( void )
{


   cout << "dest Environment" << endl;
   delete pFactory;
   // delete coward;
   delete foreseeing;
   // delete gregarious;
   // delete kamikaze;

}


void Environment::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   // check new births
   if ( (float)std::rand()/(float)RAND_MAX < birthRate )
   {

      Bug         *pBug = pFactory->birth();
      addMember( *pBug );

   }

   // check new clones
   cloneBugs();
   
      // check detections TODO

   // bugs live their life (i.e. move or die)
   bugAct();

   // check collisions
   checkCollisions();

   // draw bugs
   drawBugs();
}


int Environment::nbNeighbours( const Bug & b )
{

   int         nb = 0;


   for ( std::vector<Bug>::iterator it = listeBugs.begin() ; it != listeBugs.end() ; ++it )
      if ( !(b == *it) && b.detect(*it) )
         ++nb;

   return nb;

}

Bug* Environment::closestNeighbour( const Bug & b )
{
   double distanceMin = 0;
   double distIt = 0;
   Bug *retBug;
   for ( std::vector<Bug>::iterator it = listeBugs.begin() ; it != listeBugs.end() ; ++it )
      if ( !(b == *it) && b.detect(*it) ){
         distIt = std::sqrt( (it->x-b.x)*(it->x-b.x) + (it->y-b.y)*(it->y-b.y) );
         if (distIt < distanceMin)
         {
            distanceMin = distIt;
            retBug = &(*it);
         }
      }
   return retBug;

}

void Environment::createInitialPopulation(BugSpeciesFactory & factory) {

   for ( int i = 0 ; i < 10 ; ++i ) {

      Bug         *pBug = factory.birth();
      addMember( *pBug );

   }

}

void Environment::init() {

   // environment parameters maybe should be passed as arguments
   birthRate = 0.1;
   cloneRate = 0.1;
   angularVisionMin = 0.1;
   angularVisionMax = 0.5;
   visionDisanceMin = 10;
   visionDistanceMax = 50;
   hearingDistanceMin = 10;
   hearingDistanceMax = 50;
   kamikazeRate = 0.2;
   cowardRate = 0.2;
   gregariousRate = 0.2;
   foreseeingRate = 0.2;
   persoMultipleRate = 0.2;
   shellRate = 0.2;
   finRate = 0.2;
   eyesRate = 0.2;
   earsRate = 0.2;
   collisionDeathRate = 0.2;

   // create factory
   this->pFactory = new *BugSpeciesFactory();

   // create behaviours
   //Behaviour *kamikaze = new Kamikaze();
   //Behaviour *coward = new Coward();
   //Behaviour *gregarious = new Gregarious();
   Behaviour *foreseeing = new Foreseeing();
   //Behaviour *persoMultiple = new PersoMultiple();

   // create initial population
   createInitialPopulation(&factory);

}

void Environment::checkCollisions() {

   for ( std::vector<Bug>::iterator it = listeBugs.begin() ; it != listeBugs.end() ; ++it )
      for ( std::vector<Bug>::iterator it2 = listeBugs.begin() ; it2 != listeBugs.end() ; ++it2 )
         if ( it != it2 && it->x == it2->x && it->y == it2->y )
            
            //check if the bug dies of collision
            if ( (float)std::rand()/(float)RAND_MAX < collisionDeathRate )
               it->die();
            
}

void Environment::bugAct() {
   for ( std::vector<Bug>::iterator it = listeBugs.begin() ; it != listeBugs.end() ; ++it )
      it->action(*this);

}

void drawBugs() {

   for ( std::vector<Bug>::iterator it = listeBugs.begin() ; it != listeBugs.end() ; ++it )
      it->draw(*this);

}

void cloneBugs() {
      for ( std::vector<Bug>::iterator it = listeBugs.begin() ; it != listeBugs.end() ; ++it )
      if ( (float)std::rand()/(float)RAND_MAX < birthRate )
         addMember( *pFactory->clone(*it) );

}