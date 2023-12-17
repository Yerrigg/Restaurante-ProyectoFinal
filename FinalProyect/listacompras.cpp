#include "listacompras.h"
#include "basicas.h"
#include "venta.h"

nodoCompra *listaCompras::getCab() const
{
    return cab;
}

void listaCompras::setCab(nodoCompra *value)
{
    cab = value;
}

unsigned short listaCompras::getNCom() const
{
    return nCom;
}

void listaCompras::setNCom(unsigned short value)
{
    nCom = value;
}
listaCompras::listaCompras()
{   this->cab = NULL;
    this->nCom = 0;

}

listaCompras::~listaCompras()
{

}

void listaCompras::insertarCompra(compra *com){
    nodoCompra *aux = new nodoCompra();
    nodoCompra *temp = new nodoCompra();
    temp->setCom(com);
    temp->setSgnte(NULL) ;
    if (this->cab == NULL)
        this->setCab(temp);
    else{
        aux = this->cab;
        while (aux->getSgnte() != NULL){
            aux = aux->getSgnte();
        }
        aux->setSgnte(temp);
    }
    this->nCom++;
}


