#include <sstream>
#include "Celda.h"
#include <map>
#include <cstdlib>

using namespace std;

Celdas::Celdas(){}
Celdas::~Celdas(){}

void Celdas::MatrizHoja() // Hacemos nuestra matriz
{
    for (auto i = 'A'; i <= 'Z'; i++)
    {
        for (auto j = 1; j <= 10; j++)
        {
            std::stringstream ss;
            ss << i << j;
            mapadeceldas[ss.str()] = 0; // celdas = 0
        }
    }
    
}

void Celdas::asignarValorCelda(const string& celda, int valor)
{
    mapadeceldas[celda] = valor; // cada celda tiene un valor
}

bool Celdas::ValidarCelda(const string& celda)
{
    return celda.size() == 2 && (celda[0] >= 'A' && celda[0] <= 'Z') && (celda[1] >= '1' && celda[1] <= '10');
}

int Celdas::obtenerValorCelda(const string& celda)
{
    return mapadeceldas[celda]; // Da el valor de la celda
}

bool Celdas::esOperador(char operador)
{
    return operador == '+' || operador == '-' || operador == '*' || operador == '/';
}

bool Celdas::esNumero(const string& CadenaIngresada)
{
    for (char Numero : CadenaIngresada)
    {
        if (Numero < '0' || Numero > '9')
        {
            return false;
        } 
    } 
}

vector<string> Celdas::dividirOperacion(const string& CadenaIngresada)
{
    vector<string> elementos;
    string temp;
    for (auto i : CadenaIngresada) // Se va a dividir la cadena ingresada por el usuario, i toma cada elemento de CadenaIngresada
    {
        if ((i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z'))
        {
            temp += i;
        }
        else if (esOperador(i)) // si "i" es un operador
        {
            if (!temp.empty()) // si temp no está vacío, ".empty returna true si no hay nada en el vector, pero se convierte en una negación gracias al !" 
            {
                elementos.push_back(temp); // agrega elementos al final del vector.
                temp.clear(); // elimina los elementos del contenedor.
            }
            string op(1, i);
            elementos.push_back(op);  
        }
    }
    if (!temp.empty())
    {
        elementos.push_back(temp); // Agrega el último número o celda
    }
    return elementos;
}

int Celdas::realizarOperacion(int a, int b, char op)
{
    switch (op)
    {
    case '+':
    return a + b;
    case '-':
    return a - b;
    case '*':
    return a * b;
    case '/':
    return b =! 0 ? a / b : 0; // se pregunta si b es diferente de cero, si es así, opera.
    default:
    return 0;
    }
}

int Celdas::calcularOperacion(const string& CadenaIngresada)
{
    vector<string> elementos = dividirOperacion(CadenaIngresada); // divide la cadena en partes
    vector<int> valores;
    vector<char> operadores;
    
    for (const auto& elem : elementos) // elem toma cada valor del vector elementos
    {
        if (esNumero(elem))
        {
            valores.push_back(stoi(elem)); // stoi tranforma de string a entero
        }
        else if (ValidarCelda(elem))
        {
            valores.push_back(obtenerValorCelda(elem));
        }
        else if (esOperador(elem[0]))
        {
            operadores.push_back(elem[0]);
        }
    }

    while (!operadores.empty()) // si no está vacío
    {
        int a = valores.back(); valores.pop_back();
        int b = valores.back(); valores.pop_back();
        char op = operadores.back(); operadores.pop_back();
        valores.push_back(realizarOperacion(b, a, op)); // opera
    }
    
    return valores.back(); // resultado final;
}
