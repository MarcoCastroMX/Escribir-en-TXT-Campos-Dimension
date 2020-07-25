#ifndef CLASSA_H
#define CLASSA_H
#include <iostream>
#include <string.h>
#include "ClassB.h"

using namespace std;

class ClassA
{
private:
    string cadena;
    int llavePrimaria;
    ClassB arreglo[10];
    int contElementos;
public:
    ClassA();
    ClassA(string,int,ClassB[],int);
    string getCadena();
    void setCadena(string);
    int getLlavePrimaria();
    void setLlavePrimaria(int);
    int getContElementos();
    void setContElementos(int);
    ClassB* getArreglo();
};

#endif // CLASSA_H
