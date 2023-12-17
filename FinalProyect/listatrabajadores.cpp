#include "listatrabajadores.h"
#include "basicas.h"
#include <sstream>
#include <fstream>
#include <string.h>
const string nombreArchivoTra = "..\\Trabajadores.txt";
const char limite = '_';

nodoTrabajadores *listaTrabajadores::getCab() const
{
    return cab;
}

void listaTrabajadores::setCab(nodoTrabajadores *value)
{
    cab = value;
}

unsigned short listaTrabajadores::getNlTra() const
{
    return nlTra;
}

void listaTrabajadores::setNlTra(unsigned short value)
{
    nlTra = value;
}
listaTrabajadores::listaTrabajadores()
{
    this->nlTra = 0;
    this->cab =NULL;
}

listaTrabajadores::~listaTrabajadores()
{

}

void listaTrabajadores:: registrarTrabajador(){
    system("cls");
    Trabajadores *tra = new Trabajadores();
    tra->leerTrabajadores();
    this->insetarTrabajador(tra);
    this->guardarTrabajadorArchivo(tra);
    basicas::gotoxy(35,14); cout<<"El trabajador se ha registrado correctamente \n.";
    Sleep(1000);
}

void listaTrabajadores::insetarTrabajador(Trabajadores *tra){
    nodoTrabajadores *aux = new nodoTrabajadores();
    nodoTrabajadores *temp = new nodoTrabajadores();
    temp->setTra(tra);
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
    this->nlTra++;
}

void listaTrabajadores::mostrarTra(Trabajadores *tra, int x){
    basicas::gotoxy(30, 5+x); cout <<tra->getCodigo();
    basicas::gotoxy(45, 5 + x); cout <<tra->getNombre();
    basicas::gotoxy(65, 5+x);cout << tra->getDni();
    basicas::gotoxy(75,5+x);cout <<tra->getSueldo();
}

void listaTrabajadores::encabezadoTra(){
    basicas::gotoxy(30, 3); cout << "Cod. Tra";
    basicas::gotoxy(45, 3); cout << "Nombre ";
    basicas::gotoxy(65, 3); cout << "Dni";
    basicas::gotoxy(75, 3); cout << "Sueldo";


    basicas::gotoxy(30, 4); cout << "=======================================================";
}


void listaTrabajadores::listarTrabajadores(){
    system("cls");
    if ( this->nlTra == 0) {
        system("cls");
        basicas::gotoxy(40, 10); cout << "No existen Trabajadores Registrados!";
        cin.ignore().get();
        return;
    }

    nodoTrabajadores *aux = new nodoTrabajadores;
    int x = 1;
    aux = this->cab;
    encabezadoTra();
    while (aux != NULL) {
        mostrarTra( aux->getTra(), x);
        x++;
        aux = aux->getSgnte();
    }
    cout<<endl;
    cin.ignore().get();
}

void listaTrabajadores::recuperarTrabajadores( ){
    string linea;
    string codigo, nombre, dni, sueldo;
    ifstream archivo(nombreArchivoTra.c_str(), ios_base::in);
    while(getline(archivo,linea)){
        Trabajadores *tra = new Trabajadores();
         stringstream input_stringstream(linea);
         getline (input_stringstream, codigo, limite);
         getline (input_stringstream, nombre, limite);
         getline (input_stringstream, dni, limite);
         getline (input_stringstream, sueldo, limite);
         tra->setCodigo(codigo);
         tra->setNombre(nombre);
         tra->setDni(dni);
         tra->setSueldo( strtof(sueldo.c_str(),NULL));
         this->insetarTrabajador( tra);
    }
    archivo.close();
}

void listaTrabajadores:: guardarTrabajadorArchivo(Trabajadores *tra){
    ofstream archivo;
    archivo.open(nombreArchivoTra.c_str(), ios_base :: app | ios_base::out);
    if (archivo.is_open()){
        archivo <<tra->getCodigo()<< limite
                    <<tra->getNombre()<< limite
                    <<tra->getDni()<< limite
                    <<tra->getSueldo()<< endl;
        archivo.close();
    }
}
nodoTrabajadores *listaTrabajadores::elegirTrabajadores(){
    system("cls");
    if (this->getCab() == NULL) {
        basicas::gotoxy(30, 6);
        cout << "No hay Trabajadores en la lista";
        Sleep(1500);
        return NULL;
    }
    nodoTrabajadores* aux = this->getCab();
    int x = 1;
    while(aux != NULL){
        basicas::gotoxy(2,2); cout << "-----------------------------------------------" << endl;
        basicas::gotoxy(2,1); cout<< " || SELECIONAR TRABAJADOR || ";
        basicas::gotoxy(2,3 + x);cout << x << " > Codigo: "<<aux->getTra()->getCodigo()<<" -  Nombre: "<<aux->getTra()->getNombre();
        x++;
        aux = aux->getSgnte();
    }
    int opcion;
    do {
        basicas::gotoxy(2, 6 + x);
        cout << "Elige un trabajador: ";
        cin >> opcion;
    } while (opcion < 1 || opcion >= x);
    aux = this->getCab();
    for (int i = 1; i < opcion; i++) {
        aux = aux->getSgnte();
    }
    return aux;
}




