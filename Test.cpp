
#include <Gtest/Gtest.h>
#include "Jeu.h"

TEST(test_jouable, depasse)
{
    Jeu nouvJeu;
    Coord C(-5,-5);
    EXPECT_FALSE(nouvJeu.jouable(C,1));
    EXPECT_FALSE(nouvJeu.jouable(C,-1));
}

TEST(test_vivant, vide)
{
    Jeu nouvJeu;
    int i=0;
    Coord C(0,0);
    
    EXPECT_TRUE(nouvJeu.jouable(C,1));
    EXPECT_TRUE(nouvJeu.jouable(C,-1));
}

TEST(test_test)
{
    Jeu nouvJeu;
    Coord C(0,0);
    int* couleur=new int;
    *couleur=2;
    
    EXPECT_EQ(nouvJeu.test(C,couleur),nouvJeu.P->getTaille()*nouvJeu.P->getTaille());
}