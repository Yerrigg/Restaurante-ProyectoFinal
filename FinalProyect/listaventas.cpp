#include "listaventas.h"

nodoVenta *listaVentas::getCab() const
{
    return cab;
}

void listaVentas::setCab(nodoVenta *value)
{
    cab = value;
}

unsigned short listaVentas::getNVen() const
{
    return nVen;
}

void listaVentas::setNVen(unsigned short value)
{
    nVen = value;
}
listaVentas::listaVentas()
{
    this->cab = NULL;
    this->nVen = 0;
}

listaVentas::~listaVentas()
{

}

void listaVentas::insertarVenta(venta *ven){
    nodoVenta *aux = new nodoVenta();
    nodoVenta *temp = new nodoVenta();
    temp->setVen(ven);
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
    this->nVen++;
}

void listaVentas::registrarVentas(nodoClientes *eC, nodoTrabajadores *eT){
    venta *ven = new venta();
    ven->setClie(eC->getClie());
    ven->setTra(eT->getTra());
    ven->leerVenta();
    this->insertarVenta(ven);
}

nodoVenta *listaVentas::elegirVenta(){
    system("cls");
    if (this->getCab() == NULL){
        basicas::gotoxy(30,6); cout << "No hay ventas registradas";
        Sleep(1500);
        return NULL;
    }

    nodoVenta *aux = this->getCab();
    int x = 1;
    while(aux != NULL){
        basicas::gotoxy(2,2); cout << "-----------------------------------------------" << endl;
        basicas::gotoxy(2,1); cout<< " || SELECIONAR VENTA || ";
        basicas::gotoxy(2,3 + x);cout << x << " > Codigo: "<<aux->getVen()->getCodigo()<<" -  Encargado: "<<aux->getVen()->getTra()->getNombre()<<" - Cliente: "<<aux->getVen()->getClie()->getNombre();
        x++;
        aux = aux->getSgnte();
    }
    int opcion;
    do {
        basicas::gotoxy(2, 6 + x);
        cout << "Elija una Venta: ";
        cin >> opcion;
    } while (opcion < 1 || opcion >= x);
    aux = this->getCab();
    for (int i = 1; i < opcion; i++) {
        aux = aux->getSgnte();
    }
    return aux;
}

void listaVentas::imprimirBoleta(){
    nodoVenta *eV = new nodoVenta();
    if(this->getCab() == NULL){
        system("cls");
        basicas::gotoxy(35,10); cout << "No hay ventas registradas";
        Sleep(2000);
        return;
    }
    system("cls");
    eV = this->elegirVenta();
    eV->getVen()->boletaFinal();
}

void listaVentas::buscarVentasPorFecha(){
    system("cls");
    std::string fechaBuscada;
    nodoVenta *aux = this->getCab();
    float gananciaTotal = 0.0;
    basicas::gotoxy(45, 10); cout << "Ingrese la fecha que desea buscar (formato: DD/MM/AAAA): ";
    cin.ignore();
    getline(cin,fechaBuscada);
    while (aux != NULL) {
        if (aux->getVen()->getFecha() == fechaBuscada) {
            gananciaTotal += aux->getVen()->getMontoTotal();
        }
        aux = aux->getSgnte();
    }
    // Mostrar resultados
    system("cls");
    basicas::gotoxy(35, 10); cout << "GANANCIAS DE LA FECHA:  " << fechaBuscada << endl;
    if (gananciaTotal > 0.0) {
        basicas::gotoxy(35, 12); cout << "Ganancia Total: " << gananciaTotal << endl;
    } else {
        basicas::gotoxy(35, 12); cout << "No se encontraron ventas para la fecha buscada." << endl;
    }
    basicas::gotoxy(35,13); cout << " "<<endl;
    system("pause");
}


