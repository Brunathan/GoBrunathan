/* 
 * File:   Coord.cpp
 * Author: Brunathan
 * 
 * Created on 1 décembre 2014, 10:48
 */

#include "Coord.h"

// constructeur de coordonnées avec (0,0) comme valeurs par défaut
Coord::Coord() {
    x=0;
    y=0;
}
// constructeur de coordonnées paramétrées par x et y
Coord::Coord(int _x,int _y)
{
    x=_x;
    y=_y;
}