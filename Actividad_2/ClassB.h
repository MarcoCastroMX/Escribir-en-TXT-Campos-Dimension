#ifndef CLASSB_H
#define CLASSB_H
#include <iostream>
#include <sstream>

using namespace std;

class ClassB
{
private:
    float flotante;
    bool booleano;
public:
    ClassB();
    ClassB(float,bool);
    float getFlotante();
    void setFlotante(float);
    bool getBooleano();
};

#endif // CLASSB_H
