#include "Kamikaze.h"
#include "Bug.h"
#include "Environment.h"

Kamikaze::Kamikaze() {}
Kamikaze::~Kamikaze() {}

void Kamikaze::move(Environment & monEnvironment, Bug & b) {
    int            xLim = monEnvironment.getWidth();
    int            yLim = monEnvironment.getHeight();
    int            x = b.x;
    int            y = b.y;
    double         cumulX = b.cumulX;
    double         cumulY = b.cumulY;
    double         orientation = b.orientation;
    double         vitesse = b.vitesse;

    double         nx, ny;
    double         dx = cos( orientation )*vitesse;
    double         dy = -sin( orientation )*vitesse;
    int            cx, cy;

    cx = static_cast<int>( cumulX ); cumulX -= cx;
    cy = static_cast<int>( cumulY ); cumulY -= cy;

    nx = x + dx + cx;
    ny = y + dy + cy;

    if ( (nx < 0) || (nx > xLim - 1) ) {
        orientation = M_PI - orientation;
        cumulX = 0.;
    }
    else {
        x = static_cast<int>( nx );
        cumulX += nx - x;
    }

    if ( (ny < 0) || (ny > yLim - 1) ) {
        orientation = -orientation;
        cumulY = 0.;
    }
    else {
        y = static_cast<int>( ny );
        cumulY += ny - y;
    }

    Bug *closestBug = monEnvironment.closestNeighbour(b);

    b.x = x;
    b.y = y;
    b.cumulX = cumulX;
    b.cumulY = cumulY;
    b.orientation = orientation;
    b.vitesse = vitesse;
}
