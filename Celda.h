#ifndef __CELDA_H__
#define __CELDA_H__

#include <vector>
#include <string>
#include <map>

class Celdas 
{
public:
    Celdas(); //Constructor
    virtual ~Celdas();
    void MatrizHoja();
    void asignarValorCelda(const string&, int);
    bool ValidarCelda(const std::string&);
    int obtenerValorCelda(const std::string&);
    int calcularOperacion(const std::string&);
    bool esOperador(char);
    bool esNumero(const string&);
    int realizarOperacion(int, int, char);
    std::vector<std::string> dividirOperacion(const std::string&);

        
    std::map<std::string, int> mapadeceldas; // Mapa de celdas
};


#endif