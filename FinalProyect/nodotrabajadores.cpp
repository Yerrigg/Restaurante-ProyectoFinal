#include "nodotrabajadores.h"


nodoTrabajadores *nodoTrabajadores::getSgnte() const
{
    return sgnte;
}

void nodoTrabajadores::setSgnte(nodoTrabajadores *value)
{
    sgnte = value;
}



Trabajadores *nodoTrabajadores::getTra() const
{
    return tra;
}

void nodoTrabajadores::setTra(Trabajadores *value)
{
    tra = value;
}
nodoTrabajadores::nodoTrabajadores()
{

}

nodoTrabajadores::~nodoTrabajadores()
{

}

