#include "Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

Menu::Menu()
{

}

int Menu::menuPrincipal(){
    int resp,resp2;
    cout<<"\n\n\tCAMPOS DE DIMENSION\n"<<endl;
    cout<<"1.-Agregar.\n"<<"2.-Eliminar.\n"<<"3.-Mostrar.\n"<<"4.-Modificar.\n"<<"5.-Mostrar Todos.\n"<<"6.-Salir."<<endl;
    cin>>resp;
    if(resp==1){
        cout<<"1.-Agregar al final.\n"<<"2.-Agregar al inicio."<<endl;
        cin>>resp2;
        if(resp2==1)
            return 11;
        return 12;
    }
    else if(resp==4){
        cout<<"1.-Cadena.\n"<<"2.-Entero"<<endl;
        cin>>resp2;
        if(resp2==1)
            return 41;
        return 42;
    }
    return resp;
}

bool Menu::existe_llave(string nomArchivo,int llaveBuscada)
{
    ifstream fin;
    string Cadena;
    int Longitud,llave,contClassB;
    float flotante;
    bool booleano;

    fin.open(nomArchivo, ios::binary);
    if(fin.is_open()){
        while(!fin.eof()){
            fin.read((char*)&Longitud,4);
            if(fin.eof())
                break;

            char cadenaCaracteres[Longitud];
            fin.read(cadenaCaracteres,Longitud);

            fin.read((char*)&llave,4);

            if(llave==llaveBuscada)
                return true;
            else {
                fin.read((char*)&contClassB,4);
                for(int i=0;i<contClassB;i++){
                    fin.read((char*)&flotante,sizeof(float));
                    fin.read((char*)&booleano,1);
                }
            }
        }
    }
    fin.close();
    return false;

}
