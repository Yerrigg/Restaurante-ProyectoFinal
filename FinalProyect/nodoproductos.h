#ifndef NODOPRODUCTOS_H
#define NODOPRODUCTOS_H
#include "productos.h"

class nodoProductos
{
protected:
    productos *pro;
    nodoProductos *sgnte;
public:
    nodoProductos();
    ~nodoProductos();
    productos *getPro() const;
    void setPro(productos *value);
    nodoProductos *getSgnte() const;
    void setSgnte(nodoProductos *value);
};

#endif // NODOPRODUCTOS_H
