#ifndef NODOVENTA_H
#define NODOVENTA_H
#include "venta.h"

class nodoVenta
{
protected:
    venta *ven;
    nodoVenta *Sgnte;

public:
    nodoVenta();
    ~nodoVenta();
    venta *getVen() const;
    void setVen(venta *value);
    nodoVenta *getSgnte() const;
    void setSgnte(nodoVenta *value);
};

#endif // NODOVENTA_H
