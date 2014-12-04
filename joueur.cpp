/*
 * File:   joueur.cpp
 * Author: Brunathan
 * 
 * Created on 1 décembre 2014, 10:42
 */

using namespace std;
#include "joueur.h"

// ajoute des prisonniers à un joueur
 void joueur::ajoutPrisonniers(int nb)
 {
     nbPrisonniers+=nb;
 } 
// étape de jeu, le joueur choisi la case où il veut jouer
 Coord joueur::choixJeu() // (-1,-1) pour passer son tours 
 {
     Coord c;
     cout<<endl<<"x = ";
     cin>>c.x;
     cout<<endl<<"y = ";
     cin>>c.y;
     dernierTour=c;
     return c;
 }  
// retourne un booléen disant si le joueur a passé
 bool joueur::aPasse ()
 {
     if(dernierTour.x==-1 && dernierTour.y==-1) return true;
     else return false;
 }