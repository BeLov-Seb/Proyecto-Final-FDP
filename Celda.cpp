#include <sstream>
#include "Celda.h"
#include <map>
#include <cstdlib>

using namespace std;

Celdas::Celdas(){}
// Hacemos nuestra matriz:
void Celdas::MatrizHoja(){
    for (auto i = 'A'; i <= 'Z'; i++)
    {
        for (auto j = 1; j <= 10; j++)
        {
            std::stringstream ss;
            ss << i << j;
            celdas[ss.str()] = 0; // celdas = 0
        }
    }
    
}

int Celdas::obtener(const string& celda)
{
    return celdas[celda]; // Da el valor de la celda
}
