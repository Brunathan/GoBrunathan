/* 
 * File:   Plateau.cpp
 * Author: Brunathan
 * 
 * Created on 1 décembre 2014, 10:35
 */

#include "Plateau.h"

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

int Plateau::getIntersection(Coord C) const
{
    return tab[C.x][C.y];
    
}
void Plateau::placerPion(Coord C, int couleur)
{
    tab[C.x][C.y]=couleur;
}

void Plateau::affichage(){
    for(unsigned int i=0;i<taille;i++)
    {
        for(unsigned int j=0;j<taille;j++)
        {
            switch tab[i][j]
            {
                case -1:
                {cout<<"O ";}
                case 0: 
                {cout<<". ";}
                case 1:
                {cout<<"X ";}
            }
            
        }
        cout<<endl;
    } 
}

