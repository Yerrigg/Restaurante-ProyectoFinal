#ifndef LISTACOMPRAS_H
#define LISTACOMPRAS_H
#include "nodocompra.h"

class listaCompras
{
protected:
    nodoCompra *cab;
    unsigned short nCom;
public:
    listaCompras();
    ~listaCompras();
    nodoCompra *getCab() const;
    void setCab(nodoCompra *value);
    unsigned short getNCom() const;
    void setNCom(unsigned short value);
    void registrarCompras();
    void insertarCompra(compra *com);
};

#endif // LISTACOMPRAS_H
