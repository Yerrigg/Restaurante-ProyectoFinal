#include "nodoclientes.h"


nodoClientes *nodoClientes::getSgnte() const
{
    return sgnte;
}

void nodoClientes::setSgnte(nodoClientes *value)
{
    sgnte = value;
}

clientes *nodoClientes::getClie() const
{
    return clie;
}

void nodoClientes::setClie(clientes *value)
{
    clie = value;
}
nodoClientes::nodoClientes()
{

}

nodoClientes::~nodoClientes()
{

}

