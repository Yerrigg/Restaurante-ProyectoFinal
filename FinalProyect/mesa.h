#ifndef MESA_H
#define MESA_H
#include "clientes.h"

class mesa
{
protected:
    int id;
    bool ocupada;
    int maxComensales;
public:
    mesa();
    ~mesa();
    int getId() const;
    void setId(int value);
    bool getOcupada() const;
    void setOcupada(bool value);
    int getMaxComensales() const;
    void setMaxComensales(int value);
    void leerMesa();

};

#endif // MESA_H
