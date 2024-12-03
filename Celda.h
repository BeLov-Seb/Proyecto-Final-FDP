#ifndef __CELDA_H__
#define __CELDA_H__

#include <iostream>


using namespace std;

class Celda 
{
    public:
        bool esunaformula;
        std:: string formula;
        double valor;

        Celda();
        void tenervalor(double);
        
    
};

#endif