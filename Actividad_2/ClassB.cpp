#include "ClassB.h"


ClassB::ClassB()
{

}

ClassB::ClassB(float flotante, bool booleano)
{
    this->flotante=flotante;
    this->booleano=booleano;
}

float ClassB::getFlotante()
{
    return flotante;
}

void ClassB::setFlotante(float flotante)
{
    this->flotante = flotante;
}

bool ClassB::getBooleano(){
    return booleano;
}

