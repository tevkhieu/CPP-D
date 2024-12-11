#include "Foreseeing.h"
#include <iostream>

Foreseeing::Foreseeing() {}

Foreseeing::~Foreseeing() {}

void Foreseeing::move(Environment & monEnvironment, Bug & b) {
    std::cout << "Foreseeing is carefully planning its movement!" << std::endl;
    int            xLim = monEnvironment.getWidth();
    int            yLim = monEnvironment.getHeight();
    int            x = b.x;
    int            y = b.y;
    double         cumulX = b.cumulX;
    double         cumulY = b.cumulY;
    double         orientation;
    double         vitesse;

    double         nx, ny;
    int            cx, cy;

    double nearestBugOrientation;
    double nearestBugVitesse;

    b.cumulX = cumulX;
    b.cumulY = cumulY;
    b.orientation = orientation;
    b.vitesse = vitesse;

    Bug *closestBug = monEnvironment.closestNeighbour(b);
    nearestBugOrientation = closestBug->getOrientation();
    nearestBugVitesse = closestBug->getVitesse();

    dx = cos( nearestBugOrientation )*vitesse;
    dy = sin( nearestBugOrientation )*vitesse;

    cx = static_cast<int>( cumulX ); cumulX -= cx;
    cy = static_cast<int>( cumulY ); cumulY -= cy;

    nx = x + dx + cx;
    ny = y + dy + cy;

    if ( (nx < 0) || (nx > xLim - 1) ) {
        b.orientation = M_PI - orientation;
        b.cumulX = 0.;
    }
    else {
        b.x = static_cast<int>( nx );
        b.cumulX += nx - x;
    }

    if ( (ny < 0) || (ny > yLim - 1) ) {
        b.orientation = -orientation;
        b.cumulY = 0.;
    }
    else {
        b.y = static_cast<int>( ny );
        b.cumulY += ny - y;
    }

}
