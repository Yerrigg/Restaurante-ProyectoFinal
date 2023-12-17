#include "mesa.h"
#include "basicas.h"

int mesa::getId() const
{
    return id;
}

void mesa::setId(int value)
{
    id = value;
}

bool mesa::getOcupada() const
{
    return ocupada;
}

void mesa::setOcupada(bool value)
{
    ocupada = value;
}



int mesa::getMaxComensales() const
{
    return maxComensales;
}

void mesa::setMaxComensales(int value)
{
    maxComensales = value;
}


mesa::mesa()
{
    this->id = 0;
    this->maxComensales=0;
}

mesa::~mesa()
{
    
}
void mesa::leerMesa()
{
    basicas::imprimirPantalla2();
    basicas::gotoxy(25,5); this->setId( basicas::leerEntero("Ingrese el ID de mesa: "));
    basicas::gotoxy(25,6); this->setMaxComensales( basicas::leerEntero("Ingrese numero de comensales: "));
    basicas::gotoxy(25,7); this->setOcupada (basicas::leerEstado("Ingrese estado mesa <<O:Ocupado || D:Descupado>> : "));
}
