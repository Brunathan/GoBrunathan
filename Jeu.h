/* 
 * File:   Jeu.h
 * Author: Brunathan
 *
 * Created on 1 décembre 2014, 10:53
 */

#ifndef JEU_H
#define	JEU_H

#include "Coord.h"
#include "Plateau.h"
#include "joueur.h"

class Jeu {
public:
    Jeu() ;
    bool jouable(Coord C, int Couleur);
    bool suicide(Coord C, int Couleur);
    void modifs();
    void run();
    bool fin();
private:
    Plateau P;
    joueur jBlanc , jNoir;
    
};
#endif	/* JEU_H */
