#ifndef NODOMESAS_H
#define NODOMESAS_H
#include "mesa.h"

class nodoMesas
{
protected:
    nodoMesas *sgnte;
    mesa *mes;
public:
    nodoMesas();
    ~nodoMesas();
    nodoMesas *getSgnte() const;
    void setSgnte(nodoMesas *value);
    mesa *getMes() const;
    void setMes(mesa *value);
};

#endif // NODOMESAS_H
