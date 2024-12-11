#ifndef _BUG_H_
#define _BUG_H_


#include "UImg.h"

#include <iostream>
#include <Behaviour.h>

using namespace std;


class Environment;


class Bug
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

public :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   Behaviour       * behaviour;
   T               * couleur;
   int maxAge;
   int birthEpoch;

private :
   void move( int xLim, int yLim );

public :                                           
   Bug( void );  
   Bug( const Bug & b );
   ~Bug( void );
                                                   
   void action( Environment & monEnvironment );
   void draw( UImg & support );

   void detect( const Bug & b ) const;
   double getOrientation() const { return orientation; };
   double getVitesse() const { return vitesse; };

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bug & b1, const Bug & b2 );

   bool dieOldAge(Environment & monEnvironment);
   void die();
   Behaviour *getBehaviour() { return behaviour;}
   void setBehaviour(Behaviour *behaviour) { this->behaviour = behaviour;}

};


#endif
