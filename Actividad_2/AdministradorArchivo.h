#ifndef ADMINISTRADORARCHIVO_H
#define ADMINISTRADORARCHIVO_H
#include <iostream>
#include <ClassA.h>
#include <ClassB.h>
#include <fstream>
#include <cstring>

using namespace std;

class AdministradorArchivo
{
public:
    AdministradorArchivo();
    void InsertarFinal(string,ClassA);
    void InsertarInicio(string,ClassA);
    void MostrarTodos(string);
    void Eliminar(string,int);
    void Mostrar(string,int);
    void ModificarCadena(string,int,string);
    void ModificarLlaves(string,int,int);
};

#endif // ADMINISTRADORARCHIVO_H
