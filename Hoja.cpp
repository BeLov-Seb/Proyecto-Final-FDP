#include "Hoja.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

Hoja::Hoja(){}

void Hoja::mostrarmatriz()
{
    for (auto i = 'A'; i <= 'Z'; i++){}
    for (auto j = 1; j <= 5; j++)
    {
        for (auto k = 'A'; k <= 'Z'; k++)
        {
            stringstream ss;
            ss << j << k;
            cout << celdas.obtener(ss.str());
        }
        cout<<endl;
    }
        
}