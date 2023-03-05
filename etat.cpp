#include "etat.h"
#include <iostream>

bool E0::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.fin(s, new E1);
        break;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return true;
    }
    return false;
}

bool E1::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case FIN:
        return true;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return true;
    }
    return false;
}

bool E2::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.fin(s, new E6);
        break;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return true;
    }
    return false;
}

bool E3::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
    {
        Symbole *stackedS = automate.symboles.top();
        automate.symboles.pop();
        Entier *e = dynamic_cast<Entier *>(stackedS);
        ExpressionCste *exp = new ExpressionCste(e->getValeur());
        automate.reduction(1, exp);
        break;
    }
    default:
        automate.fin(new Symbole(ERREUR), NULL);
        return true;
    }
    return false;
}

bool E4::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.fin(s, new E7);
        break;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return true;
    }
    return false;
}

bool E5::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.fin(s, new E8);
        break;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return true;
    }
    return false;
}

bool E6::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case CLOSEPAR:
        automate.decalage(s, new E9);
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return true;
    }
    return false;
}

bool E7::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case MULT:
        automate.decalage(s, new E5);
        break;
    case PLUS:
    case CLOSEPAR:
    case FIN:
    {
        Symbole *stackedS1 = automate.symboles.top();
        automate.symboles.pop();
        automate.symboles.pop(); // pop second element
        Symbole *stackedS3 = automate.symboles.top();
        automate.symboles.pop();
        Expression *exp1 = dynamic_cast<Expression *>(stackedS1);
        Expression *exp2 = dynamic_cast<Expression *>(stackedS3);
        ExpressionPlus *ePlus = new ExpressionPlus(exp1, exp2);
        automate.reduction(3, ePlus);
        break;
    }
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return true;
    }
    return false;
}

bool E8::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
    {
        Symbole *stackedS1 = automate.symboles.top();
        automate.symboles.pop();
        automate.symboles.pop(); // pop second element
        Symbole *stackedS3 = automate.symboles.top();
        automate.symboles.pop();
        Expression *exp1 = dynamic_cast<Expression *>(stackedS1);
        Expression *exp2 = dynamic_cast<Expression *>(stackedS3);
        ExpressionMult *eFois = new ExpressionMult(exp1, exp2);
        automate.reduction(3, eFois);
        break;
    }
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return true;
    }
    return false;
}

bool E9::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
    {
        automate.symboles.pop();
        Symbole *stackedS2 = automate.symboles.top();
        automate.symboles.pop();
        automate.symboles.pop();
        Expression *exp = dynamic_cast<Expression *>(stackedS2);
        automate.reduction(3, exp);
        break;
    }
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return true;
    }
    return false;
}