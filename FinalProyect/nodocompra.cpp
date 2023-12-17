#include "nodocompra.h"


nodoCompra *nodoCompra::getSgnte() const
{
    return Sgnte;
}

void nodoCompra::setSgnte(nodoCompra *value)
{
    Sgnte = value;
}

compra *nodoCompra::getCom() const
{
    return com;
}

void nodoCompra::setCom(compra *value)
{
    com = value;
}
nodoCompra::nodoCompra()
{

}

nodoCompra::~nodoCompra()
{

}

