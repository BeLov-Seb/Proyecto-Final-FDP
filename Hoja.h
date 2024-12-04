#ifndef __HOJA_H__
#define __HOJA_H__

#include "Celda.h"

class Hoja
{
    public:
    Hoja();
    void mostrarmatriz();
    void IngresarDatos();

    private:
    Celdas celdas;
};

#endif