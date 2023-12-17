#include "nodomesas.h"


nodoMesas *nodoMesas::getSgnte() const
{
    return sgnte;
}

void nodoMesas::setSgnte(nodoMesas *value)
{
    sgnte = value;
}

mesa *nodoMesas::getMes() const
{
    return mes;
}

void nodoMesas::setMes(mesa *value)
{
    mes = value;
}
nodoMesas::nodoMesas()
{

}

nodoMesas::~nodoMesas()
{

}

