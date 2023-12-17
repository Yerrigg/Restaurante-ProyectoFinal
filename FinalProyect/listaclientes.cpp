#include "listaclientes.h"
#include "basicas.h"

nodoClientes *listaClientes::getCab() const
{
    return cab;
}

void listaClientes::setCab(nodoClientes *value)
{
    cab = value;
}

unsigned short listaClientes::getNClie() const
{
    return nClie;
}

void listaClientes::setNClie(unsigned short value)
{
    nClie = value;
}
listaClientes::listaClientes()
{
    this->nClie = 0;
    this->cab = NULL;
}

listaClientes::~listaClientes()
{

}
void listaClientes::registrarClientes(){
    system("cls");
    clientes *clie = new clientes;
    do{
        clie->leerClientes();
        if (idExistente(clie->getId())) {
            basicas::gotoxy(25, 14);
            cout << "Error: La ID ya esta registrada. ";
            basicas::gotoxy(25, 15);
            cout<< "Ingrese una ID diferente.\n";
            system("pause");
        }
    }while (idExistente(clie->getId()));
    this->insertarClientes(clie);
    basicas::gotoxy(30,14); cout<<"El cliente se ha registrado correctamente\n.";
    Sleep(1200);
}

void listaClientes::insertarClientes(clientes *clie){
    nodoClientes *aux = new nodoClientes;
    nodoClientes  *temp = new nodoClientes;
    temp->setClie(clie);
    temp->setSgnte(NULL);
    if  (this->cab  == NULL){
        this->setCab(temp);
    }else {
        aux = this->cab;
        while (aux->getSgnte() != NULL){
            aux  = aux->getSgnte();
        }
        aux->setSgnte(temp);
    }
    this->nClie++;
}


void listaClientes::mostrarClie(clientes *clie, int x){
    basicas::gotoxy(30,5 + x);cout<<clie->getId();
    basicas::gotoxy(40, 5 + x); cout <<clie->getNombre();
    basicas::gotoxy(65, 5+x);cout << clie->getDni();
    basicas::gotoxy(75,5+x);cout <<clie->getAcomp();
}
bool listaClientes::idExistente(int id) const {
    nodoClientes *aux = cab;
    while (aux != NULL) {
        if (aux->getClie()->getId() == id) {
            return true;
        }
        aux = aux->getSgnte();
    }
    return false;
}
nodoClientes* listaClientes::elegirClientes(){
    system("cls");
    if (this->getCab() == NULL) {
        basicas::gotoxy(30, 6);
        cout << "No hay clientes en la lista";
        Sleep(1500);
        return NULL;
    }

    nodoClientes* aux = this->getCab();
    int x = 1;
    while (aux != NULL) {
        this->encabezadoElejir();
        basicas::gotoxy(1,3+ x);cout << x << ". " << aux->getClie()->getNombre()<< " >> Comensales: "<<aux->getClie()->getAcomp()+1;
        x++;
        aux = aux->getSgnte();
    }

    int opcion;
    do {
        basicas::gotoxy(2, 6 + x);
        cout << "Elige un cliente: ";
        cin >> opcion;
    } while (opcion < 1 || opcion >= x);
    aux = this->getCab();
    for (int i = 1; i < opcion; i++) {
        aux = aux->getSgnte();
    }

    return aux;
}
void listaClientes::encabezadoClien(){
    basicas::gotoxy(30,3);cout<<"Id";
    basicas::gotoxy(40, 3); cout << "Nombre Completo ";
    basicas::gotoxy(65, 3); cout << "Dni";
    basicas::gotoxy(75, 3); cout << "Nr. Acomp";


    basicas::gotoxy(30, 4); cout << "=======================================================";
}
void listaClientes::encabezadoElejir() {
    basicas::gotoxy(0,0); cout<<"|| SELECCIONAR CLIENTE ||"<<endl;
    basicas::gotoxy(1, 2);
    cout << "ID Nombre completo             " << endl;
    cout << "-----------------------------------------------" << endl;
}



void listaClientes::listarClientes(){
    system("cls");
    if ( this->nClie == 0) {
        system("cls");
        basicas::gotoxy(40, 10); cout << "Aun no se han registrado clientes!";
        cin.ignore().get();
        return;
    }

    nodoClientes *aux = new nodoClientes;
    int x = 1;
    aux = this->cab;
    encabezadoClien();
    while (aux != NULL) {
        mostrarClie(aux->getClie(),x);
        x++;
        aux = aux->getSgnte();
    }
    cout<<endl;
    cin.ignore().get();
}
/*void listaClientes::eliminarCliente(nodoClientes* clienteEliminar) {
    if (clienteEliminar == NULL) {
        return;
    }

    // Caso especial: si el cliente a eliminar es el primer nodo de la lista
    if (clienteEliminar == this->cab) {
        this->cab = clienteEliminar->getSgnte();
        delete clienteEliminar;
        this->nClie--;
        return;
    }

    // Caso general: buscar el nodo anterior al cliente a eliminar
    nodoClientes* aux = this->cab;
    while (aux != NULL && aux->getSgnte() != clienteEliminar) {
        aux = aux->getSgnte();
    }

    // Enlazar el nodo anterior con el siguiente para "saltar" el nodo a eliminar
    if (aux != NULL) {
        aux->setSgnte(clienteEliminar->getSgnte());
        delete clienteEliminar;
        this->nClie--;
    }
}*/
