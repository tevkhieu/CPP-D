#include "Foreseeing.h"
#include <iostream>

#define M_PI 3.14159265358979323846

Foreseeing::Foreseeing() {}

Foreseeing::~Foreseeing() {}

void Foreseeing::move(Environment & monEnvironment, Bug & b) {
    std::cout << "Foreseeing is carefully planning its movement!" << std::endl;
    int            xLim = monEnvironment.getWidth();
    int            yLim = monEnvironment.getHeight();
    double         orientation;
    double         vitesse;
    float          dx, dy;
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

    cx = static_cast<int>( b.getCumulX() ); b.setCumulX(b.getCumulX() - cx);
    cy = static_cast<int>( b.getCumulY() ); b.setCumulY(b.getCumulY() - cy);

    nx = b.getX() + dx + cx;
    ny = b.getY() + dy + cy;

    if ( (nx < 0) || (nx > xLim - 1) ) {
        b.setOrientation( M_PI - orientation);
        b.setCumulX(0.);
    }
    else {
        b.x = static_cast<int>( nx );
        b.setCumulX(nx - b.getX());
    }

    if ( (ny < 0) || (ny > yLim - 1) ) {
        b.setOrientation(-orientation);
        b.setCumulY(0.);
    }
    else {
        b.y = static_cast<int>( ny );
        b.setCumulY(ny - b.getY());
    }

}
