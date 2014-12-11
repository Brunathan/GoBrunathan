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
    if(C.x<-1 || C.x>=P->getTaille() || C.y<-1 || C.y>=P->getTaille()) return false;
    if(C.x==-1 && C.y==-1) return true;
    if(P->getIntersection(C)!=0) return false;
    
    Plateau nouvPlat(*P);
    nouvPlat.placerPion(C,Couleur);
    int x=C.x;
    int y=C.y;
    
    Coord Haut(x,y+1);
    Coord Bas(x,y-1);
    Coord Gauche(x-1,y);
    Coord Droite(x+1,y);
    
    
    cout<<"a"<<endl;
    
    if(estVivant(C,nouvPlat)) return true;
    
    //La suite permet de tuer des groupes de pions en comettant un sucide 
    //(mange un groupe avec un seul oeil par exemple)
    if (Droite.x<P->getTaille() && estVivant(Droite,nouvPlat)==false)//a droite un truc meurt ? 
    {
       return true; 
    }
    if (Gauche.x>0 && estVivant(Gauche,nouvPlat)==false)//a gauche un truc meurt ? 
    {
       return true; 
    }
    if (Haut.y>0 && estVivant(Haut,nouvPlat)==false)//en haut un truc meurt ? 
    {
       return true; 
    }
    if (Bas.y<P->getTaille() && estVivant(Bas,nouvPlat)==false)//en bas un truc meurt ? 
    {
       return true; 
    }
    cout<<"b"<<endl;
    
    return false;
}

void Jeu::run()
{
    int taille;
    
    cout<<endl<<"C'est l'heure du du-d-du-duel !"<<endl;
    cout<<endl<<"Choisir la taille du plateau de jeu !"<<endl;
    cin>>taille;
    Coord LastC; //dernier mouvement
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
        
        /// ATTENTION PLANTAGE QUAND ON PASSE 
        if(jNoir.aPasse()!=true) 
        {
            P->placerPion(Choix, 1);
            LastC = Choix;
            rafraichir(P,LastC);
        }
        
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
            LastC = Choix;
            rafraichir(P,LastC);
            
        }
    }
    
    choixpris();
    
    calculScore();
    
    if(jBlanc.getScore()!=0) jBlanc.ajoutPrisonniers(2);
    if(jNoir.getScore()!=0) jNoir.ajoutPrisonniers(2);
    
    if(jBlanc.getScore() > jNoir.getScore()) cout<<endl<<"Joueur blanc a gagne !"<<endl;
    
    else cout<<endl<<"Joueur noir a gagne !"<<endl;
    
    cout<<endl<<"Scores :"<<endl<<"Noir: "<<jNoir.getScore()<<endl<<"Blanc: "<<jBlanc.getScore()<<endl;    
    
    P->affichage();
    
    cout<<endl<<"fini !"<<endl;
}

bool Jeu::fin()
{
    if(jBlanc.aPasse() && jNoir.aPasse()) return true;
    else return false;
}

bool Jeu::tested(Coord C)
{
    for(unsigned int i=0;i<T.size();i++)
    {
        if(C.x==T[i].x && C.y==T[i].y) return true;
    }
    
    return false;
}

bool Jeu::estVivant(Coord C, Plateau plat)
{
    T.push_back(C);
    
    int x=C.x;
    int y=C.y;
    
    Coord Haut(x,y+1);
    Coord Bas(x,y-1);
    Coord Gauche(x-1,y);
    Coord Droite(x+1,y);
    
    if (
        (Haut.y   < plat.getTaille() && plat.getIntersection(Haut)==0)      ||
        (Bas.y    >= 0                && plat.getIntersection(Bas)==0)       ||
        (Gauche.x >= 0               && plat.getIntersection(Gauche)==0)    ||
        (Droite.x < plat.getTaille() && plat.getIntersection(Droite)==0)  
       )
    {
        return true;
    }
    
    if((Haut.y   < plat.getTaille() &&  plat.getIntersection(Haut)    == plat.getIntersection(C) && tested(Haut)   == false && estVivant(Haut,plat))
    || (Bas.y    >= 0               &&  plat.getIntersection(Bas)     == plat.getIntersection(C) && tested(Bas)    == false && estVivant(Bas,plat))
    || (Gauche.x >= 0               &&  plat.getIntersection(Gauche)  == plat.getIntersection(C) && tested(Gauche) == false && estVivant(Gauche,plat))
    || (Droite.x < plat.getTaille() &&  plat.getIntersection(Droite)  == plat.getIntersection(C) && tested(Droite) == false && estVivant(Droite,plat)))
    {
        return true;
    }        
     
    return false;
}

void Jeu::rafraichir(Plateau* plat, Coord LastC)
{
    int x=LastC.x;
    int y=LastC.y;
    
    Coord Haut(x,y+1);
    Coord Bas(x,y-1);
    Coord Gauche(x-1,y);
    Coord Droite(x+1,y);
    Coord C;
    int i,j;
    
        C=Haut;
            
        T.clear();

        if(Haut.y>0 && estVivant(C,*plat)==false)
        {
            for(int k=0;k<T.size();k++)
            {
                C.x=T[k].x;
                C.y=T[k].y;

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
        
        C=Bas;
            
        T.clear();

        if(Bas.y<plat->getTaille() && estVivant(C,*plat)==false)
        {
            for(int k=0;k<T.size();k++)
            {
                C.x=T[k].x;
                C.y=T[k].y;

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
        
        C=Gauche;
            
        T.clear();

        if(Gauche.x>0 && estVivant(C,*plat)==false)
        {
            for(int k=0;k<T.size();k++)
            {
                C.x=T[k].x;
                C.y=T[k].y;

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
        C=Droite;
            
        T.clear();

        if(Droite.x<plat->getTaille() && estVivant(C,*plat)==false)
        {
            for(int k=0;k<T.size();k++)
            {
                C.x=T[k].x;
                C.y=T[k].y;

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
        /**/
    for(i=0;i<plat->getTaille();i++)
    {
        for(j=0;j<plat->getTaille();j++)
        {
            C.x=i;
            C.y=j;
            
            T.clear();
            
            if(estVivant(C,*plat)==false)
            {
                for(int k=0;k<T.size();k++)
                {
                    C.x=T[k].x;
                    C.y=T[k].y;
                    
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
    if (Haut.y < P->getTaille() && P->getIntersection(Haut)!=0)
    {
        if (*Couleur == 2) *Couleur = P->getIntersection(Haut);  // 2=Aucune couleur rencontrée
        if (*Couleur == -P->getIntersection(Haut)) *Couleur = 3; // 3=Couleurs différentes rencontrées
    }
        
    if (Bas.y>=0 && P->getIntersection(Bas)!=0)       
    {
        if (*Couleur == 2) *Couleur = P->getIntersection(Bas);  // 2=Aucune couleur rencontré
        if (*Couleur == -P->getIntersection(Bas)) *Couleur = 3; // 3=Couleurs différentes rencontrées
    }
    
    if (Gauche.x>=0 && P->getIntersection(Gauche)!=0)  
    {
        if (*Couleur == 2) *Couleur = P->getIntersection(Gauche);  // 2=Aucune couleur rencontré
        if (*Couleur == -P->getIntersection(Gauche)) *Couleur = 3; // 3=Couleurs différentes rencontrées
    }   
    
    if (Droite.x<P->getTaille() && P->getIntersection(Droite)!=0)  
    {
        if (*Couleur == 2) *Couleur = P->getIntersection(Droite);  // 2=Aucune couleur rencontré
        if (*Couleur == -P->getIntersection(Droite)) *Couleur = 3; // 3=Couleurs différentes rencontrées
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
        return 1+test(Gauche,Couleur);
    }   
    
    if (Droite.x<P->getTaille() && P->getIntersection(Droite)==0)  
    {
        return 1+test(Droite,Couleur);
    }
    
    return 0;
}

void Jeu::calculScore()
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
                if(*Couleur==1)  jNoir.ajoutPrisonniers(Score);
            }
        }
    }
}

void Jeu::choixpris()//a faire avant de calculer le score
{
    Coord C;
    C.x=-1;//initialisation
    C.y=-1;//initialisation
    while (C.x!=0 && C.y!=0)//tant que on a pas envie d'arrêter
    {
        
        cout<<"Entrez la coordonnée d'un prisonniers : entrez \"0\" pour terminer "<<endl;

        cout<<" premiere coordonnée (ligne) ?" <<endl;

        cin>>C.x;
        if(C.x == 0) //juste pour arrêter ici quand on a un zero
        {
            break;
        }

        cout<<"seconde coordonnée (collone) ? "<<endl;

        cin>>C.y;
        
        C.x-=1;
        C.y-=1;

        if (C.x>0 || C.y>0 || C.x<P->getTaille()||C.y<P->getTaille())//si on lui dit pas nimp
        {
            if (P->getIntersection(C)== -1)//Pion blanc
            {
                P->supprimerPion(C);
                jNoir.ajoutPrisonniers(1);
                cout<<"Un pion blanc a été supprimé"<<endl;

            }
            if (P->getIntersection(C)== 1)//Pion noir
            {
                P->supprimerPion(C);
                jBlanc.ajoutPrisonniers(1);
                cout<<"Un pion noir a été supprimé"<<endl;

            }
        }
        
        P->affichage();
    }
    
            
}