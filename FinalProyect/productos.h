#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include <iostream>
using namespace std;

class productos
{
protected:
    string nombre;
    string categoria;
    float precio;
    int stock;
public:
    productos();
    ~productos();
    string getNombre() const;
    void setNombre(const string &value);
    string getCategoria() const;
    void setCategoria(const string &value);
    float getPrecio() const;
    void setPrecio(float value);
    int getStock() const;
    void setStock(int value);
    void leerProducto();
};

#endif // PRODUCTOS_H
