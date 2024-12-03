#include <sstream>
#include "Celda.h"

Celda::Celda() : esunaformula(false), valor(0) {}

void Celda::tenervalor(double a)
{
    valor = a;
    esunaformula = false;
    formula = "";
};