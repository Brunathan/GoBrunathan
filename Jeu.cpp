/* 
 * File:   Jeu.cpp
 * Author: Brunathan
 * 
 * Created on 1 décembre 2014, 10:53
 */

#include "Jeu.h"

using namespace std;

// Teste la case C pour savoir si un pion Couleur peut y être joué
bool Jeu::jouable(Coord C, int Couleur)
{
    if(P.getIntersection(C)!=0) return false; // vérifie que la case n'est pas vide
    
    int x=C.x;  // récupère les coordonnées choisies
    int y=C.y;
    
    Coord Haut(x,y+1);  // stocke les coordonnées des cases entourant C
    Coord Bas(x,y-1);
    Coord Gauche(x-1,y);
    Coord Droite(x+1,y);
    
    if (P.getIntersection(Haut)==0 ||
        P.getIntersection(Bas)==0 ||
        P.getIntersection(Gauche)==0 ||
        P.getIntersection(Droite)==0)
    {
        return true;    // C est jouable si l'une des cases adjascente est vide
    }
    
    Plateau nouvPlat(P);
    nouvPlat.placerPion(C,Couleur);
    
    if (Couleur==1 && rafraichir(C,nouvPlat).x>0) return true;  // si le pion joué est noir et que un/des pion(s) blanc(s) seront supprimé(s), c'est jouable
    if (Couleur==-1 && rafraichir(C,nouvPlat).y>0) return true; // si le pion joué est blanc et que un/des pion(s) noir(s) seront supprimé(s), c'est jouable
    
    return false;
}
// lance le jeu
Jeu::run()
{
    cout<<endl<<"C'est l'heure du du-d-du-duel !"<<endl;        // message de bienvenue
    
    while(fin()!=true)                                          // boucle tant que le jeu n'est pas fini
    {
        Coord Choix;
        
        cout<<endl<<"Joueur noir, a toi de jouer :"<<endl;      // debut du tour du joueur noir
        
        Choix=jNoir.choixJeu();
        while(jouable(Choix,-1) != true)                        // tant que la case demandée n'est pas jouable, on demande de recommencer
        {
            cout<<endl<<"Choix non possible, veuillez entrer une position valide"<<endl;
            Choix=jNoir.choixJeu();
        }
        if(jNoir.aPasse()!=true)                                // si le joueur ne passe pas, on place le pion et on raffraichi le plateau
        {
            P.placerPion(Choix, -1);
            rafraichir(Choix);
        }

        cout<<endl<<"Joueur blanc, a toi de jouer :"<<endl;     // debut du tour du joueur blanc
        
        Choix=jBlanc.choixJeu();
        while(jouable(Choix,-1) != true)                        // tant que la case demandée n'est pas jouable, on demande de recommencer
        {
            cout<<endl<<"Choix non possible, veuillez entrer une position valide"<<endl;
            Choix=jBlanc.choixJeu();
        }
        if(jBlanc.aPasse()!=true)                               // si le joueur ne passe pas, on place le pion et on raffraichi le plateau
        {
            P.placerPion(Choix, -1);
            rafraichir(Choix);
        }
    }
    
    if(score().x > score().y) cout<<endl<<"Joueur blanc a gagne !"<<endl;
    
    else cout<<endl<<"Joueur noir a gagne !"<<endl;             // à la fin du jeu, le joueur avec le plus grans score gagne
}
// vélifie si la partie est terminée
Jeu::fin()
{
    if(jBlanc.aPasse() && jNoir.aPasse()) return true;          // le jeu se termine quand les deux joueurs ont passé
    else return false;
}