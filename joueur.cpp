/*
 * File:   joueur.cpp
 * Author: Brunathan
 * 
 * Created on 1 décembre 2014, 10:42
 */

using namespace std;
#include "joueur.h"



joueur::joueur() {
}

 void joueur::ajoutPrisonniers(int nb)
 {
     nbPrisonniers+=nb;
 }
    
 Coord joueur::choixJeu() // (-1,-1) pour passer son tours 
 {
     Coord c;
     cout<<endl<<"x = ";
     cin>>c.x;
     cout<<endl<<"y = ";
     cin>>c.y;
 }
    
 bool joueur::aPasse ()
 {
     if(dernierTour=(-1,-1)) return true;
     else return false;
 }