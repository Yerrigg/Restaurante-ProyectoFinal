#ifndef CLIENTES_H
#define CLIENTES_H
#include "persona.h"
#include <iostream>
using namespace  std;

class clientes : public Persona
{
protected:
       int id;
       int acomp;
public:
    clientes();
    ~clientes();
    int getAcomp() const;
    void setAcomp(int value);
    void leerClientes();
    int getId() const;
    void setId(int value);
};

#endif // CLIENTES_H
