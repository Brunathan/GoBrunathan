/* 
 * File:   Jeu.cpp
 * Author: Brunathan
 * 
 * Created on 1 décembre 2014, 10:53
 */

#include "Jeu.h"

using namespace std;

bool Jeu::jouable(Coord C, int Couleur)
{
    if(P.getIntersection(C)!=0) return false;
    
    int x=C.x;
    int y=C.y;
    
    Coord Haut(x,y+1);
    Coord Bas(x,y-1);
    Coord Gauche(x-1,y);
    Coord Droite(x+1,y);
    
    if (P.getIntersection(Haut)==0 ||
        P.getIntersection(Bas)==0 ||
        P.getIntersection(Gauche)==0 ||
        P.getIntersection(Droite)==0)
    {
        return true;
    }
    
    Plateau nouvPlat(P);
    nouvPlat.placerPion(C,Couleur);
    
    if (Couleur==1 && rafraichir(C,nouvPlat).x>0) return true;
    if (Couleur==-1 && rafraichir(C,nouvPlat).y>0) return true;
    
    return false;
}

Jeu::run()
{
    cout<<endl<<"C'est l'heure du du-d-du-duel !"<<endl;
    
    while(fin()!=true)
    {
        Coord Choix;
        
        cout<<endl<<"Joueur noir, a toi de jouer :"<<endl;
        
        Choix=jNoir.choixJeu();
        while(jouable(Choix,-1) != true)
        {
            cout<<endl<<"Choix non possible, veuillez entrer une position valide"<<endl;
            Choix=jNoir.choixJeu();
        }
        if(jNoir.aPasse()!=true) 
        {
            P.placerPion(Choix, -1);
            rafraichir(Choix);
        }
        
        cout<<endl<<"Joueur blanc, a toi de jouer :"<<endl;
        
        Choix=jBlanc.choixJeu();
        while(jouable(Choix,-1) != true)
        {
            cout<<endl<<"Choix non possible, veuillez entrer une position valide"<<endl;
            Choix=jBlanc.choixJeu();
        }
        if(jBlanc.aPasse()!=true) 
        {
            P.placerPion(Choix, -1);
            rafraichir(Choix);
        }
    }
    
    if(score().x > score().y) cout<<endl<<"Joueur blanc a gagne !"<<endl;
    
    else cout<<endl<<"Joueur noir a gagne !"<<endl;
}
