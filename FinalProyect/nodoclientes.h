#ifndef NODOCLIENTES_H
#define NODOCLIENTES_H
#include "clientes.h"

class nodoClientes
{
private:
    nodoClientes *sgnte;
    clientes *clie;
public:
    nodoClientes();
    ~nodoClientes();
    nodoClientes *getSgnte() const;
    void setSgnte(nodoClientes *value);
    clientes *getClie() const;
    void setClie(clientes *value);
};

#endif // NODOCLIENTES_H
