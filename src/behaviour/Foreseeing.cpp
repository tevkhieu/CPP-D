#include "Foreseeing.h"
#include "Environment.h"  // Include full definition of Environment
#include "Bug.h"           // Include full definition of Bug
#include <cmath>           // For cos, sin, etc.

void Foreseeing::move(Environment &monEnvironment, Bug &b) {
    int xLim = monEnvironment.getWidth();
    int yLim = monEnvironment.getHeight();
    
    Bug *closestBug = monEnvironment.closestNeighbour(b);
    if (closestBug) {
        nearestBugOrientation = closestBug->getOrientation();
        nearestBugVitesse = closestBug->getVitesse();
    }

    dx = std::cos(nearestBugOrientation) * vitesse;
    dy = std::sin(nearestBugOrientation) * vitesse;

    int cx = static_cast<int>(b.getCumulX());
    b.setCumulX(b.getCumulX() - cx);

    int cy = static_cast<int>(b.getCumulY());
    b.setCumulY(b.getCumulY() - cy);

    int nx = b.getX() + dx + cx;
    int ny = b.getY() + dy + cy;

    if (nx < 0 || nx >= xLim) {
        b.setOrientation(M_PI - orientation);
        b.setCumulX(0.0);
    } else {
        b.setX(static_cast<int>(nx));
        b.setCumulX(nx - b.getX());
    }

    if (ny < 0 || ny >= yLim) {
        b.setOrientation(-orientation);
        b.setCumulY(0.0);
    } else {
        b.setY(static_cast<int>(ny));
        b.setCumulY(ny - b.getY());
    }
}
