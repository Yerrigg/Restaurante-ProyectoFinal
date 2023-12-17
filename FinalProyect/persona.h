#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include "basicas.h"
using namespace std;

class Persona
{
protected:
    string nombre;
    string dni;
public:
    Persona();
    ~Persona();
    string getNombre() const;
    void setNombre(const string &value);
    string getDni() const;
    void setDni(const string &value);
};

#endif // PERSONA_H
