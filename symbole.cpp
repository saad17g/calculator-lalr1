#include "symbole.h"
#include <iostream>

void Symbole::Affiche()
{
   cout << Etiquettes[ident];
}

int Symbole::getValue()
{
   return -1;
}

void Entier::Affiche()
{
   Symbole::Affiche();
   cout << "(" << valeur << ")";
}

int Entier::getValeur()
{
   return valeur;
}

void ExpressionPlus::Affiche()
{
   Symbole::Affiche();
   gauche->Affiche();
   cout << "+";
   droite->Affiche();
}

void ExpressionMult::Affiche()
{
   Symbole::Affiche();
   gauche->Affiche();
   cout << "*";
   droite->Affiche();
}

void ExpressionCste::Affiche()
{
   Symbole::Affiche();
   cout << valeur;
}

int ExpressionPlus::Eval()
{
   int g = gauche->Eval();
   int d = droite->Eval();
   return g + d;
}

int ExpressionMult::Eval()
{
   int g = gauche->Eval();
   int d = droite->Eval();
   return g * d;
}

int ExpressionCste::Eval()
{
   return valeur;
}