#ifndef NODOCOMPRA_H
#define NODOCOMPRA_H
#include "compra.h"

class nodoCompra
{
protected:
    nodoCompra *Sgnte;
    compra *com;
public:
    nodoCompra();
    ~nodoCompra();
    nodoCompra *getSgnte() const;
    void setSgnte(nodoCompra *value);
    compra *getCom() const;
    void setCom(compra *value);
};

#endif // NODOCOMPRA_H
