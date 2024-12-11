#include "Bug.h"

#include "Environment.h"
#include "Kamikaze.h"

#include <cstdlib>
#include <cmath>


const double      Bug::AFF_SIZE = 8.;
const double      Bug::MAX_VITESSE = 10.;
const double      Bug::LIMITE_VUE = 30.;

int               Bug::next = 0;


Bug::Bug( void )
{

   identite = ++next;
   cout << "const Bug (" << identite << ") par defaut" << endl;
   behave = new Kamikaze;
   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

}


Bug::Bug(const Bug& b) {
    identite = ++next;
    std::cout << "const Bug (" << identite << ") par copie" << std::endl;

    x = b.x;
    y = b.y;
    cumulX = cumulY = 0.0;
    orientation = b.orientation;
    vitesse = b.vitesse;

    couleur = new T[3];
    std::copy(b.couleur, b.couleur + 3, couleur);
}


Bug::~Bug( void )
{

   delete[] couleur;

   cout << "dest Bug (" << identite << ")" << endl;

}

/*Initialise the coordinates of the bug*/
void Bug::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


/*Check if bug dies of old age*/
bool Bug::dieOldAge(Environment & monEnvironment) {

   return this->maxAge < monEnvironment.getEpoch() - this->birthEpoch;

}

/*Action method: perform every updates on bug during environment step*/
void Bug::action(Environment & monEnvironment) {
    // Check if the bug dies of old age.
    if (this->dieOldAge(monEnvironment)) {
        this->die(); // Call the die method.
        return;      // Exit the function.
    }

    // Perform detection.
    this->detect();

    // Call the move method and update position.
    // the update is done within the move method because it's easier than 
    // returning every new values.
    behaviour->move(monEnvironment, *this);
}

/* Not really sure about how this works honestly but it's 3am and I'm tired.*/
void Bug::draw( UImg & support )
{
   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


/*Not really sure about the purpose of this but slayy*/
bool operator==( const Bug & b1, const Bug & b2 )
{

   return ( b1.identite == b2.identite );

}


/*Clear the list of neighbouring bugs and update it with every bug detected*/
void Bug::detect( const Bug & b ) const {

}


/*Die method*/
void Bug::die() {

   delete this;
   delete couleur;
}