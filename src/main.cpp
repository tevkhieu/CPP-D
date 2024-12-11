#include "Aquarium.h"
#include "Environment.h"
#include "Bug.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   for ( int i = 1; i <= 2; ++i )
      ecosysteme.getEnvironment().addMember( Bug() );
   ecosysteme.run();


   return 0;

}
