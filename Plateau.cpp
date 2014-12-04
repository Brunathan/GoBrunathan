/* 
 * File:   Plateau.cpp
 * Author: Brunathan
 * 
 * Created on 1 décembre 2014, 10:35
 */

#include "Plateau.h"

using namespace std;
// constructeur de plateau avec une taille par défaut de 19
Plateau::Plateau() {
    taille=19;
    tab=new int*[taille];
    for(unsigned int i=0;i<taille;i++)
    {
        tab[i]=new int[taille];
    }
    for(unsigned int i=0;i<taille;i++)
    {
        for(unsigned int j=0;j<taille;j++)
        {
            tab[i][j]=0;
        }
    }
}
// constructeur de plateau avec une taille parapétrable
Plateau::Plateau(int _taille) {
    taille=_taille;
    tab=new int*[taille];
    for(unsigned int i=0;i<taille;i++)
    {
        tab[i]=new int[taille];
    }
     for(unsigned int i=0;i<taille;i++)
     {
        for(unsigned int j=0;j<taille;j++)
        {
            tab[i][j]=0;
        }
    }
}
// accès en lecture au contenu d'une intersection définir par ses coordonnées
int Plateau::getIntersection(Coord C) const
{
    return tab[C.x][C.y];
    
}
// Placement d'unpion d'une couleur donnée à une intersection
void Plateau::placerPion(Coord C, int couleur)
{
    tab[C.x][C.y]=couleur;
}
// suppression d'un pion par mise à 0 de la valeur de l'intersection
void Plateau::supprimerPion(Coord C)
{
    tab[C.x][C.y]=0;
}
// Méthode d'affichage du plateau
void Plateau::affichage(){
    for(unsigned int i=0;i<taille;i++)
    {
        for(unsigned int j=0;j<taille;j++)
        {
            switch (tab[i][j])
            {
                case -1:
                cout<<"O ";
                case 0: 
                cout<<". ";
                case 1:
                cout<<"X ";
            }
        }
        cout<<endl;
    } 
}

