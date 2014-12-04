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
    if(P->getIntersection(C)!=0) return false;
    
    Plateau nouvPlat(*P);
    nouvPlat.placerPion(C,Couleur);
    
    if(estVivant(C,nouvPlat)) return true;
    
    return false;
}

void Jeu::run()
{
    int taille;
    
    cout<<endl<<"C'est l'heure du du-d-du-duel !"<<endl;
    cout<<endl<<"Choisir la taille du plateau de jeu !"<<endl;
    cin>>taille;
    
    P = new Plateau(taille);
    
    while(fin()!=true)
    {
        Coord Choix;
        
        P->affichage();
        
        cout<<endl<<"Joueur noir, a toi de jouer :"<<endl;
        
        Choix=jNoir.choixJeu();
        
        while(jouable(Choix,1) != true)
        {
            cout<<endl<<"Choix non possible, veuillez entrer une position valide"<<endl;
            Choix=jNoir.choixJeu();
        }
        if(jNoir.aPasse()!=true) 
        {
            P->placerPion(Choix, 1);
            rafraichir(P);
        }
        
        system("clear"); 
        
        P->affichage();
        
        cout<<endl<<"Joueur blanc, a toi de jouer :"<<endl;
        
        Choix=jBlanc.choixJeu();
        while(jouable(Choix,-1) != true)
        {
            cout<<endl<<"Choix non possible, veuillez entrer une position valide"<<endl;
            Choix=jBlanc.choixJeu();
        }
        if(jBlanc.aPasse()!=true) 
        {
            P->placerPion(Choix, -1);
            rafraichir(P);
        }
    }
    
    //if(score().x > score().y) cout<<endl<<"Joueur blanc a gagne !"<<endl;
    
    //else cout<<endl<<"Joueur noir a gagne !"<<endl;
    
    
    cout<<endl<<"fini !"<<endl;
}

bool Jeu::fin()
{
    if(jBlanc.aPasse() && jNoir.aPasse()) return true;
    else return false;
}

bool Jeu::estVivant(Coord C, Plateau plat)
{
    
    int x=C.x;
    int y=C.y;
    
    Coord Haut(x,y+1);
    Coord Bas(x,y-1);
    Coord Gauche(x-1,y);
    Coord Droite(x+1,y);
    
    if (
        (Haut.y<plat.getTaille() && plat.getIntersection(Haut)==0)      ||
        (Bas.y>=0 && plat.getIntersection(Bas)==0)                      ||
        (Gauche.x>=0 && plat.getIntersection(Gauche)==0)                ||
        (Droite.x<plat.getTaille() && plat.getIntersection(Droite)==0)  
       )
    {
        return true;
    }
    
    if((plat.getIntersection(Haut)   == plat.getIntersection(C) && estVivant(Haut,plat))
    || (plat.getIntersection(Droite) == plat.getIntersection(C) && estVivant(Droite,plat))
    || (plat.getIntersection(Gauche) == plat.getIntersection(C) && estVivant(Gauche,plat))
    || (plat.getIntersection(Bas)    == plat.getIntersection(C) && estVivant(Bas,plat)))
    {
        return true;
    }        
    
    return false;
}

void Jeu::rafraichir(Plateau* plat)
{
    Coord C;
    
    for(C.x=0;C.x<plat->getTaille();C.x++)
    {
        for(C.y=0;C.y<plat->getTaille();C.y++)
        {
            if(estVivant(C,*plat)==false)
            {
                if(plat->getIntersection(C)==-1) 
                {
                    jNoir.ajoutPrisonniers(1);
                    plat->placerPion(C,0);
                }
                if(plat->getIntersection(C)==1) 
                {
                    jBlanc.ajoutPrisonniers(1);
                    plat->placerPion(C,0);
                }
                plat->placerPion(C,0);
            }
        }
    }
}

int Jeu::test(Coord C, int* Couleur)
{
    P->placerPion(C,4);
    
    int x=C.x;
    int y=C.y;
    
    Coord Haut(x,y+1);
    Coord Bas(x,y-1);
    Coord Gauche(x-1,y);
    Coord Droite(x+1,y);
    
    /*  CASES ADJACENTES NON VIDES  */
    if (Haut.y<P->getTaille() && P->getIntersection(Haut)!=0)
    {
        if (*Couleur == 2) *Couleur = P->getIntersection(Haut);  // 2=Aucune couleur rencontré
        if (*Couleur == -P->getIntersection(Haut)) *Couleur == 3; // 3=Couleurs différentes rencontrées
    }
        
    if (Bas.y>=0 && P->getIntersection(Bas)!=0)       
    {
        if (*Couleur == 2) *Couleur = P->getIntersection(Bas);  // 2=Aucune couleur rencontré
        if (*Couleur == -P->getIntersection(Bas)) *Couleur == 3; // 3=Couleurs différentes rencontrées
    }
    
    if (Gauche.x>=0 && P->getIntersection(Gauche)!=0)  
    {
        if (*Couleur == 2) *Couleur = P->getIntersection(Gauche);  // 2=Aucune couleur rencontré
        if (*Couleur == -P->getIntersection(Gauche)) *Couleur == 3; // 3=Couleurs différentes rencontrées
    }   
    
    if (Droite.x<P->getTaille() && P->getIntersection(Droite)!=0)  
    {
        if (*Couleur == 2) *Couleur = P->getIntersection(Droite);  // 2=Aucune couleur rencontré
        if (*Couleur == -P->getIntersection(Droite)) *Couleur == 3; // 3=Couleurs différentes rencontrées
    }
    
    /*  CASES ADJACENTES VIDES  */
    
    if (Haut.y<P->getTaille() && P->getIntersection(Haut)==0)
    {
        return 1+test(Haut,Couleur);
    }
        
    if (Bas.y>=0 && P->getIntersection(Bas)==0)       
    {
        return 1+test(Bas,Couleur);
    }
    
    if (Gauche.x>=0 && P->getIntersection(Gauche)==0)  
    {
        return 1+test(Bas,Couleur);
    }   
    
    if (Droite.x<P->getTaille() && P->getIntersection(Droite)==0)  
    {
        return 1+test(Bas,Couleur);
    }
    
    return 0;
}

Coord Jeu::score()
{
    Coord C;
    int Score;
    int* Couleur=new int;
    
    for(C.x=0;C.x<P->getTaille();C.x++)
    {
        for(C.y=0;C.y<P->getTaille();C.y++)
        {
            if(P->getIntersection(C)==0) 
            {
                *Couleur=2;
                Score=test(C,Couleur); 
                if(*Couleur==-1) jBlanc.ajoutPrisonniers(Score);
                if(*Couleur==1) jNoir.ajoutPrisonniers(Score);
            }
        }
    }
}