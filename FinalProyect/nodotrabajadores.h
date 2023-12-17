#ifndef NODOTRABAJADORES_H
#define NODOTRABAJADORES_H
#include "trabajadores.h"

class nodoTrabajadores
{
private:
    nodoTrabajadores *sgnte;
    Trabajadores *tra;
public:
    nodoTrabajadores();
    ~nodoTrabajadores();
    nodoTrabajadores *getSgnte() const;
    void setSgnte(nodoTrabajadores *value);
    Trabajadores *getTra() const;
    void setTra(Trabajadores *value);
};

#endif // NODOTRABAJADORES_H
