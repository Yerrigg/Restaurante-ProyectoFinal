#include "persona.h"


string Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const string &value)
{
    nombre = value;
}

string Persona::getDni() const
{
    return dni;
}

void Persona::setDni(const string &value)
{
    dni = value;
}
Persona::Persona()
{

}

Persona::~Persona()
{

}

