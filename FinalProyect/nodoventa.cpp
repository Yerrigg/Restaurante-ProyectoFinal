#include "nodoventa.h"


venta *nodoVenta::getVen() const
{
    return ven;
}

void nodoVenta::setVen(venta *value)
{
    ven = value;
}

nodoVenta *nodoVenta::getSgnte() const
{
    return Sgnte;
}

void nodoVenta::setSgnte(nodoVenta *value)
{
    Sgnte = value;
}
nodoVenta::nodoVenta()
{

}

nodoVenta::~nodoVenta()
{

}

