/* 
 * File:   Coord.h
 * Author: Brunathan
 *
 * Created on 1 décembre 2014, 10:48
 */

#ifndef COORD_H
#define	COORD_H

class Coord {
public:
    Coord();                // constructeur de coordonnées avec (0,0) comme valeurs par défaut
    Coord(int _x,int _y);   // constructeur de coordonnées paramétrées par x et y
    int x;
    int y;
private:
};

#endif	/* COORD_H */

