 #ifndef TRABAJADORES_H
#define TRABAJADORES_H
#include <iostream>
#include "persona.h"
using namespace std;

class Trabajadores : public Persona
{
private:
    string codigo;
    float sueldo;
public:
    Trabajadores();
    ~Trabajadores();
    string getCodigo() const;
    void setCodigo(const string &value);
    float getSueldo() const;
    void setSueldo(float value);
    void leerTrabajadores();

};

#endif // TRABAJADORES_H
