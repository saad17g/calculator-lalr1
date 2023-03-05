#pragma once

#include <stack>
#include <string>
#include "symbole.h"
#include "lexer.h"
using namespace std;

class Etat;

class Automate
{

public:
   Automate(string stream);
   ~Automate() {}
   void decalage(Symbole *s, Etat *e);
   void reduction(int n, Symbole *s);
   void fin(Symbole *s, Etat *e);
   bool calculate();

   // todo: méthodes popSymboles
public:
   stack<Etat *> etats;
   stack<Symbole *> symboles;
   Lexer *lexer;
   int resultat;
};
