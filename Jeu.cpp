/* 
 * File:   Jeu.cpp
 * Author: Brunathan
 * 
 * Created on 1 décembre 2014, 10:53
 */

#include "Jeu.h"

using namespace std;

Jeu::Jeu() {
    
}

bool Jeu::suicide (Coord C, int Couleur)
{
    Plateau nouvPlat;
    
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
