#include "AdministradorArchivo.h"

AdministradorArchivo::AdministradorArchivo()
{

}

void AdministradorArchivo::InsertarFinal(string nomArchivo, ClassA obj)
{
    ofstream fout;
    fout.open(nomArchivo,ios::binary|ios::app);
    string cadena=obj.getCadena();
    int longitud=cadena.length();
    fout.write((char*)&longitud,4);
    char cadenaCaracteres[longitud];
    strcpy(cadenaCaracteres,cadena.c_str());
    fout.write(cadenaCaracteres,longitud);

    int llave=obj.getLlavePrimaria();
    fout.write((char*)&llave,4);

    int contClassB=obj.getContElementos();
    fout.write((char*)&contClassB,4);
    for(int i=0;i<contClassB;i++){
        ClassB arreglo=obj.getArreglo()[i];
        float flotante=arreglo.getFlotante();
        fout.write((char*)&flotante,sizeof(float));
        bool boolean =arreglo.getBooleano();
        fout.write((char*)&boolean,1);
    }
    fout.close();
}

void AdministradorArchivo::InsertarInicio(string nomArchivo,ClassA obj)
{
    ofstream fout;
    ifstream fin;
    string Cadena;
    int Longitud,llave,contClassB;
    float flotante;
    bool booleano;

    fout.open("Archivo.bin",ios::binary|ios::app);
    string cadena=obj.getCadena();
    int longitud=cadena.length();
    fout.write((char*)&longitud,4);
    char cadenaCaracteres[longitud];
    strcpy(cadenaCaracteres,cadena.c_str());
    fout.write(cadenaCaracteres,longitud);

    llave=obj.getLlavePrimaria();
    fout.write((char*)&llave,4);

    contClassB=obj.getContElementos();
    fout.write((char*)&contClassB,4);
    for(int i=0;i<contClassB;i++){
        ClassB arreglo=obj.getArreglo()[i];
        float flotante=arreglo.getFlotante();
        fout.write((char*)&flotante,sizeof(float));
        bool boolean =arreglo.getBooleano();
        fout.write((char*)&boolean,1);
    }

    fin.open(nomArchivo, ios::binary);
    if(fin.is_open()){
        while(!fin.eof()){
            fin.read((char*)&Longitud,4);
            if(fin.eof())
                break;
            fout.write((char*)&Longitud,4);
            char cadenaCaracteres[Longitud];
            fin.read(cadenaCaracteres,Longitud);
            fout.write(cadenaCaracteres,Longitud);

            fin.read((char*)&llave,4);
            fout.write((char*)&llave,4);

            fin.read((char*)&contClassB,4);
            fout.write((char*)&contClassB,4);
            for(int i=0;i<contClassB;i++){
                fin.read((char*)&flotante,sizeof(float));
                fout.write((char*)&flotante,sizeof(float));
                fin.read((char*)&booleano,1);
                fout.write((char*)&booleano,1);
            }
        }
    }
    fin.close();
    fout.close();
    remove(nomArchivo.c_str());
    rename("Archivo.bin",nomArchivo.c_str());

}

void AdministradorArchivo::MostrarTodos(string nomArchivo){
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
            char cadenaCaracteres[Longitud+1];
            fin.read(cadenaCaracteres,Longitud);
            cadenaCaracteres[Longitud]='\0';
            Cadena=cadenaCaracteres;

            fin.read((char*)&llave,4);

            fin.read((char*)&contClassB,4);
            cout<<"\n\nCadena: "<<Cadena<<"\nLlave: "<<llave;
            for(int i=0;i<contClassB;i++){
                fin.read((char*)&flotante,sizeof(float));
                fin.read((char*)&booleano,1);
                if(booleano==true)
                    cout<<"\nFlotante: "<<flotante<<"\nBooleano: True ";
                else
                    cout<<"\nFlotante: "<<flotante<<"\nBooleano: False ";
            }
        }
    }
    fin.close();
}

void AdministradorArchivo::Eliminar(string nomArchivo, int llaveEliminar)
{
    ofstream fout;
    ifstream fin;
    string Cadena;
    int Longitud,llave,contClassB;
    float flotante;
    bool booleano;

    fout.open("Archivo.bin",ios::binary|ios::app);
    fin.open(nomArchivo, ios::binary);
    if(fin.is_open()){
        while(!fin.eof()){
            fin.read((char*)&Longitud,4);
            if(fin.eof())
                break;

            char cadenaCaracteres[Longitud];
            fin.read(cadenaCaracteres,Longitud);
            Cadena=cadenaCaracteres;

            fin.read((char*)&llave,4);

            if(llave!=llaveEliminar){
                fout.write((char*)&Longitud,4);
                fout.write(cadenaCaracteres,Longitud);
                fout.write((char*)&llave,4);
                fin.read((char*)&contClassB,4);
                fout.write((char*)&contClassB,4);
                for(int i=0;i<contClassB;i++){
                    fin.read((char*)&flotante,sizeof(float));
                    fout.write((char*)&flotante,sizeof(float));
                    fin.read((char*)&booleano,1);
                    fout.write((char*)&booleano,1);
                }
            }
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
    fout.close();
    remove(nomArchivo.c_str());
    rename("Archivo.bin",nomArchivo.c_str());
}

void AdministradorArchivo::Mostrar(string nomArchivo, int llaveMostrar)
{
    ofstream fout;
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

            char cadenaCaracteres[Longitud+1];
            fin.read(cadenaCaracteres,Longitud);
            cadenaCaracteres[Longitud]='\0';
            Cadena=cadenaCaracteres;

            fin.read((char*)&llave,4);

            if(llave==llaveMostrar){
                fin.read((char*)&contClassB,4);
                cout<<"\n\nCadena: "<<Cadena<<"\nLlave: "<<llave;
                for(int i=0;i<contClassB;i++){
                    fin.read((char*)&flotante,sizeof(float));
                    fin.read((char*)&booleano,1);
                    if(booleano==true)
                        cout<<"\nFlotante: "<<flotante<<"\nBooleano: True ";
                    else
                        cout<<"\nFlotante: "<<flotante<<"\nBooleano: False ";
                }
            }
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
}

void AdministradorArchivo::ModificarCadena(string nomArchivo, int llaveModificar, string Modificar)
{
    ofstream fout;
    ifstream fin;
    string Cadena;
    int Longitud,llave,contClassB;
    float flotante;
    bool booleano;

    fout.open("Archivo.bin",ios::binary|ios::app);
    fin.open(nomArchivo, ios::binary);
    if(fin.is_open()){
        while(!fin.eof()){
            fin.read((char*)&Longitud,4);
            if(fin.eof())
                break;

            char cadenaCaracteres[Longitud];
            fin.read(cadenaCaracteres,Longitud);

            fin.read((char*)&llave,4);

            if(llave==llaveModificar){
                Longitud=Modificar.length();
                fout.write((char*)&Longitud,4);

                char caracteresmodificar[Longitud];
                strcpy(caracteresmodificar,Modificar.c_str());
                fout.write(caracteresmodificar,Longitud);

                fout.write((char*)&llave,4);

                fin.read((char*)&contClassB,4);
                fout.write((char*)&contClassB,4);
                for(int i=0;i<contClassB;i++){
                    fin.read((char*)&flotante,sizeof(float));
                    fout.write((char*)&flotante,sizeof(float));
                    fin.read((char*)&booleano,1);
                    fout.write((char*)&booleano,1);
                }
            }
            else {
                fout.write((char*)&Longitud,4);
                fout.write(cadenaCaracteres,Longitud);
                fout.write((char*)&llave,4);
                fin.read((char*)&contClassB,4);
                fout.write((char*)&contClassB,4);
                for(int i=0;i<contClassB;i++){
                    fin.read((char*)&flotante,sizeof(float));
                    fout.write((char*)&flotante,sizeof(float));
                    fin.read((char*)&booleano,1);
                    fout.write((char*)&booleano,1);
                }
            }
        }
    }
    fin.close();
    fout.close();
    remove(nomArchivo.c_str());
    rename("Archivo.bin",nomArchivo.c_str());
}

void AdministradorArchivo::ModificarLlaves(string nomArchivo, int llaveModificar, int Modificar)
{
    ofstream fout;
    ifstream fin;
    string Cadena;
    int Longitud,llave,contClassB;
    float flotante;
    bool booleano;

    fout.open("Archivo.bin",ios::binary|ios::app);
    fin.open(nomArchivo, ios::binary);
    if(fin.is_open()){
        while(!fin.eof()){
            fin.read((char*)&Longitud,4);
            if(fin.eof())
                break;

            char cadenaCaracteres[Longitud];
            fin.read(cadenaCaracteres,Longitud);

            fin.read((char*)&llave,4);

            if(llave==llaveModificar){
                fout.write((char*)&Longitud,4);
                fout.write(cadenaCaracteres,Longitud);

                fout.write((char*)&Modificar,4);

                fin.read((char*)&contClassB,4);
                fout.write((char*)&contClassB,4);
                for(int i=0;i<contClassB;i++){
                    fin.read((char*)&flotante,sizeof(float));
                    fout.write((char*)&flotante,sizeof(float));
                    fin.read((char*)&booleano,1);
                    fout.write((char*)&booleano,1);
                }
            }
            else {
                fout.write((char*)&Longitud,4);
                fout.write(cadenaCaracteres,Longitud);
                fout.write((char*)&llave,4);
                fin.read((char*)&contClassB,4);
                fout.write((char*)&contClassB,4);
                for(int i=0;i<contClassB;i++){
                    fin.read((char*)&flotante,sizeof(float));
                    fout.write((char*)&flotante,sizeof(float));
                    fin.read((char*)&booleano,1);
                    fout.write((char*)&booleano,1);
                }
            }
        }
    }
    fin.close();
    fout.close();
    remove(nomArchivo.c_str());
    rename("Archivo.bin",nomArchivo.c_str());

}
