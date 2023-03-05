#ifndef SYMBOLE_H

#define SYMBOLE_H

#include <string>
#include <map>
using namespace std;

enum Identificateurs
{
   OPENPAR,
   CLOSEPAR,
   PLUS,
   MULT,
   INT,
   FIN,
   ERREUR,
   EXPR
};

const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

class Symbole
{
public:
   Symbole(int i) : ident(i) {}
   virtual ~Symbole() {}
   operator int() const { return ident; }
   virtual void Affiche();
   virtual int getValue();

protected:
   int ident;
};

class Entier : public Symbole
{
public:
   Entier(int v) : Symbole(INT), valeur(v) {}
   ~Entier() {}
   virtual void Affiche();
   int getValeur();

protected:
   int valeur;
};

class Expression : public Symbole
{
public:
   Expression() : Symbole(EXPR) {}
   ~Expression() {}
   virtual void Affiche() = 0;
   virtual int Eval() = 0;

protected:
};

class ExpressionBinaire : public Expression
{
public:
   ExpressionBinaire(Expression *gauche, Expression *droite) : gauche(gauche), droite(droite) {}
   ~ExpressionBinaire() {}

protected:
   Expression *gauche;
   Expression *droite;
};

class ExpressionPlus : public ExpressionBinaire
{
public:
   ExpressionPlus(Expression *gauche, Expression *droite) : ExpressionBinaire(gauche, droite) {}
   ~ExpressionPlus() {}
   virtual void Affiche();
   int Eval();

protected:
};

class ExpressionMult : public ExpressionBinaire
{
public:
   ExpressionMult(Expression *gauche, Expression *droite) : ExpressionBinaire(gauche, droite) {}
   ~ExpressionMult() {}
   virtual void Affiche();
   int Eval();

protected:
};

class ExpressionCste : public Expression
{
public:
   ExpressionCste(int val) : valeur(val) {}
   ~ExpressionCste() {}
   virtual void Affiche();
   int Eval();

protected:
   int valeur;
};

#endif