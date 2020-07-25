#include "ClassA.h"

ClassA::ClassA()
{

}

ClassA::ClassA(string cadena, int llave, ClassB arreglo[], int numElementos)
{
    this->cadena=cadena;
    this->llavePrimaria=llave;
    this->contElementos=numElementos;
    for (int i=0;i<numElementos;i++){
        this->arreglo[i]=arreglo[i];
    }
}

string ClassA::getCadena()
{
    return cadena;
}

void ClassA::setCadena(string cadena)
{
    this->cadena = cadena;
}

int ClassA::getLlavePrimaria()
{
    return llavePrimaria;
}

void ClassA::setLlavePrimaria(int llave)
{
    llavePrimaria = llave;
}

int ClassA::getContElementos()
{
    return contElementos;
}

void ClassA::setContElementos(int numero)
{
    contElementos = numero;
}

ClassB *ClassA::getArreglo()
{
    return arreglo;
}
