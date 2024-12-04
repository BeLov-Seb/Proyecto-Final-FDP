#ifndef __CELDA_H__
#define __CELDA_H__

#include <vector>
#include <string>
#include <map>

class Celdas 
{
public:
    Celdas(); //Constructor
    void MatrizHoja();
    int obtener(const std::string& celda);

        
    std::map<std::string, int> celdas; // Mapa de celdas
};

#endif