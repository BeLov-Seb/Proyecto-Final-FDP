#include "Hoja.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

Hoja::Hoja(){}
Hoja::~Hoja(){}

void Hoja::mostrarmatriz()
{
    cout << "   ";
    for (auto i = 'A'; i <= 'Z'; i++)
    {
        cout << " " << i << " ";
    }
    cout << endl;

    for (auto j = 1; j <= 10; j++)
    {
        cout << j << " ";
        for (auto i = 'A'; i <= 'Z'; i++)
        {
            stringstream ss;
            ss << j << i;
            cout << "  " << celdas.obtener(ss.str());
        }
        cout << endl;
    }
        
}

bool Hoja::ingresarOperacion(const string& CadenaIngresada)
{
    size_t posicion_igual = CadenaIngresada.find('=');
    if (posicion_igual = string::npos)
    {
        return false;
    }
    string celda = CadenaIngresada.substr(0, posicion_igual);
    string expresion = CadenaIngresada.substr(posicion_igual + 1);

    if (!celdas.ValidarCelda(celda))
    {
        return false;
    }
    
    int resultado = celdas.
}

void Hoja::IngresarDatos(){
    string CadenaIngresada;
    while (true)
    {
        cout << "Ingrese una operación: ";
        getline(cin, CadenaIngresada);
        if ()
        {
            /* code */
        }
        
    }
    
}