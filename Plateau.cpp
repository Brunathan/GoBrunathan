/* 
 * File:   Plateau.cpp
 * Author: Brunathan
 * 
 * Created on 1 décembre 2014, 10:35
 */

#include "Plateau.h"

using namespace std;
// constructeur de plateau avec une taille par défaut de 19
Plateau::Plateau() 
{
    taille=19;
    tab=new int*[taille]; // création de taille tableau
    for(unsigned int i=0;i<taille;i++)
    {
        tab[i]=new int[taille]; // création de taille case dans chaque tableau
    }
    for(unsigned int i=0;i<taille;i++)
    {
        for(unsigned int j=0;j<taille;j++)
        {
            tab[i][j]=0; // Initialisation à 0 du tableau
        }
    }
}
// constructeur de plateau qui copie le plateau argument
Plateau::Plateau(const Plateau& P)
{
    Coord C;
    taille=P.getTaille();
    tab=new int*[taille]; // création de taille tableau
    for(unsigned int i=0;i<taille;i++)
    {
        tab[i]=new int[taille]; // création de taille case dans chaque tableau
    }
    for(C.x=0;C.x<P.getTaille();C.x++)
    {
        for(C.y=0;C.y<P.getTaille();C.y++)
        {
            tab[C.x][C.y]=P.getIntersection(C); // Initialisation du tableau avec les valeurs de l'argument
        }
    }
}
// constructeur de plateau avec une taille parapétrable
Plateau::Plateau(int _taille) 
{
    taille=_taille;
    tab=new int*[taille];// création de taille tableau
    for(unsigned int i=0;i<taille;i++)
    {
        tab[i]=new int[taille]; // création de taille case dans chaque tableau
    }
     for(unsigned int i=0;i<taille;i++)
     {
        for(unsigned int j=0;j<taille;j++)
        {
            tab[i][j]=0;// Initialisation à 0 du tableau
        }
    }
}
// accès en lecture au contenu d'une intersection définir par ses coordonnées
int Plateau::getIntersection(Coord C) const
{
    return tab[C.x][C.y];
    
}
// accès en lecture de la taille du plateau voila
int Plateau::getTaille() const
{
    return taille;
}

// Placement d'un pion d'une couleur donnée à une intersection
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
void Plateau::affichage()
{
    for (unsigned int i=0;i<taille;i++) 
    {
    cout<<" "<<i+1;
    }
    cout<<" X"<<endl;
    for(unsigned int j=0;j<taille;j++) // appel taille fois à la rédaction d'une ligne
    {
        cout<<j+1;

        for(unsigned int i=0;i<taille;i++) // rédaction d'une ligne
        {
            if(tab[i][j] == -1)     cout<<"O "; // O correspond au joueur Blanc
            if(tab[i][j] ==  1)     cout<<"X "; // X correspond au joueur Noir
            if(tab[i][j] ==  0)     cout<<". "; // . correspond à une case vide

        }
        cout<<endl;
    }
    cout<<"Y"<<endl;
} 


