#include "automate.h"
#include "etat.h"
#include <iostream>

void Automate::decalage(Symbole *s, Etat *e)
{
    symboles.push(s);
    etats.push(e);
    lexer->Avancer();
}

void Automate::fin(Symbole *s, Etat *e)
{
    symboles.push(s);
    etats.push(e);
}

void Automate::reduction(int n, Symbole *s)
{
    for (int i = 0; i < n; i++)
    {
        delete (etats.top());
        etats.pop();
    }
    etats.top()->transition(*this, s);
}

Automate::Automate(string stream)
{
    lexer = new Lexer(stream);
    E0 *firstState = new E0();
    etats.push(firstState);
}

bool Automate::calculate()
{
    bool nextState = true;
    while (nextState)
    {
        Symbole *s = lexer->Consulter();
        s->Affiche();
        cout << endl;
        nextState = !etats.top()->transition(*this, s);
    }

    if (*symboles.top() != ERREUR)
    {
        resultat = ((Expression *)symboles.top())->Eval();
        return true;
    }
    return false;
}