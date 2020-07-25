#include <iostream>
#include <fstream>
#include "Menu.h"
#include "ClassA.h"
#include "ClassB.h"
#include "AdministradorArchivo.h"

using namespace std;

int main()
{
    Menu menu;
    AdministradorArchivo admin;
    ifstream fin;
    ofstream fout;
    string nomArchivo,cadena;
    int opc,llave,numElementos,numBooleano,nuevaLlave;
    float flotante;
    bool booleano;
    do{
        opc=menu.menuPrincipal();
        bool Band=false;
        switch (opc){
            case 11:{
                cout<<"\tAGREGAR AL FINAL\n"<<endl;
                cout<<"Inserte el nombre del Archivo:"<<endl;
                cin>>nomArchivo;
                cout<<"Inserte una cadena: "<<endl;
                cin>>cadena;
                cout<<"Inserte una llave primaria:"<<endl;
                cin>>llave;
                if(menu.existe_llave(nomArchivo,llave)){
                    cout<<"Llave ya Existente"<<endl;
                    break;
                }
                cout<<"Ingrese numero de elementos a ingresar en el arreglo: (Max 10)"<<endl;
                cin>>numElementos;
                if(numElementos>10 || numElementos<0){
                    cout<<"Numero Invalido"<<endl;
                    break;
                }
                ClassB arreglo[numElementos];
                for(int i=0;i<numElementos;i++){
                    cout<<"Ingrese un numero: "<<endl;
                    cin>>flotante;
                    cout<<"Ingresea un 1 si quiere True o 0 si quiere False:"<<endl;
                    cin>>numBooleano;
                    if(numBooleano<0 || numBooleano>1){
                        cout<<"Numero Invalido"<<endl;
                        Band=true;
                        break;
                    }
                    if(numBooleano==1)
                        booleano=true;
                    else
                        booleano=false;
                    ClassB objB(flotante,booleano);
                    arreglo[i]=objB;
                }
                if(Band==true)
                    break;
                ClassA obj(cadena,llave,arreglo,numElementos);
                admin.InsertarFinal(nomArchivo,obj);
                break;
            }
            case 12:{
                cout<<"\tAGREGAR AL INICIO\n"<<endl;
                cout<<"Inserte el nombre del Archivo:"<<endl;
                cin>>nomArchivo;
                cout<<"Inserte una cadena: "<<endl;
                cin>>cadena;
                cout<<"Inserte una llave primaria:"<<endl;
                cin>>llave;
                if(menu.existe_llave(nomArchivo,llave)){
                    cout<<"Llave ya Existente"<<endl;
                    break;
                }
                cout<<"Ingrese numero de elementos a ingresar en el arreglo: (Max 10)"<<endl;
                cin>>numElementos;
                if(numElementos>10|| numElementos<0){
                    cout<<"Numero Invalido"<<endl;
                    break;
                }
                ClassB arreglo[numElementos];
                for(int i=0;i<numElementos;i++){
                    cout<<"Ingrese un numero: "<<endl;
                    cin>>flotante;
                    cout<<"Ingresea un 1 si quiere True o 0 si quiere False:"<<endl;
                    cin>>numBooleano;
                    if(numBooleano<0 || numBooleano>1){
                        cout<<"Numero Invalido"<<endl;
                        Band=true;
                        break;
                    }
                    if(numBooleano==1)
                        booleano=true;
                    else
                        booleano=false;
                    ClassB objB(flotante,booleano);
                    arreglo[i]=objB;
                }
                if(Band==true)
                    break;
                ClassA obj(cadena,llave,arreglo,numElementos);
                admin.InsertarInicio(nomArchivo,obj);
                break;
            }
            case 2:{
                cout<<"\tELIMINAR\n"<<endl;
                cout<<"Inserte el nombre del Archivo:"<<endl;
                cin>>nomArchivo;
                cout<<"Inserte la llave primaria a Eliminar:"<<endl;
                cin>>llave;
                if(!menu.existe_llave(nomArchivo,llave)){
                    cout<<"Llave y/o Archivo Inexistente"<<endl;
                    break;
                }
                admin.Eliminar(nomArchivo,llave);
                break;
            }
            case 3:{
                cout<<"\tMOSTRAR\n"<<endl;
                cout<<"Inserte el nombre del Archivo:"<<endl;
                cin>>nomArchivo;
                cout<<"Inserte la llave primaria a Mostrar:"<<endl;
                cin>>llave;
                if(!menu.existe_llave(nomArchivo,llave)){
                    cout<<"Llave y/o Archivo Inexistente"<<endl;
                    break;
                }
                admin.Mostrar(nomArchivo,llave);
                break;
            }
            case 41:{
                cout<<"\tMODIFICAR CADENA\n"<<endl;
                cout<<"Inserte el nombre del Archivo:"<<endl;
                cin>>nomArchivo;
                cout<<"Inserte la llave primaria:"<<endl;
                cin>>llave;
                if(!menu.existe_llave(nomArchivo,llave)){
                    cout<<"Llave y/o Archivo Inexistente"<<endl;
                    break;
                }
                cout<<"Inserte la cadena a Modificar:"<<endl;
                cin>>cadena;
                admin.ModificarCadena(nomArchivo,llave,cadena);
                break;
            }
            case 42:{
                cout<<"\tMODIFICAR ENTERO\n"<<endl;
                cout<<"Inserte el nombre del Archivo:"<<endl;
                cin>>nomArchivo;
                cout<<"Inserte la llave primaria:"<<endl;
                cin>>llave;
                if(!menu.existe_llave(nomArchivo,llave)){
                    cout<<"Llave y/o Archivo Inexistente"<<endl;
                    break;
                }
                cout<<"Inserte la nueva a llave:"<<endl;
                cin>>nuevaLlave;
                if(menu.existe_llave(nomArchivo,nuevaLlave)){
                    cout<<"Llave ya Existente"<<endl;
                    break;
                }
                admin.ModificarLlaves(nomArchivo,llave,nuevaLlave);
                break;
            }
            case 5:{
                cout<<"\tMOSTRAR TODOS\n"<<endl;
                cout<<"Inserte el nombre del Archivo:"<<endl;
                cin>>nomArchivo;
                admin.MostrarTodos(nomArchivo);
                break;
            }
            case 6:{
                cout<<"\tSALIR\n"<<endl;
            }
        }
    }while(opc!=6);
    return 0;
}
