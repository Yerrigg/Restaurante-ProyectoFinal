#include "nodoproductos.h"


productos *nodoProductos::getPro() const
{
    return pro;
}

void nodoProductos::setPro(productos *value)
{
    pro = value;
}

nodoProductos *nodoProductos::getSgnte() const
{
    return sgnte;
}

void nodoProductos::setSgnte(nodoProductos *value)
{
    sgnte = value;
}
nodoProductos::nodoProductos()
{

}

nodoProductos::~nodoProductos()
{

}

