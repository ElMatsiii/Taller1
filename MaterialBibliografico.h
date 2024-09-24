#pragma once
#include <string>
#include <iostream>
using namespace std;

class MaterialBibliografico {
    public:
        MaterialBibliografico(string nombre, string isbn, string autor, string prestado);//constructor
        virtual string mostrarInformacion();//funcion
        virtual ~MaterialBibliografico();//destructor
        string getNombre();
        string getIsbn();
        string getAutor();
        string getPrestado();
        void setPrestado(string a);
    protected:
        string nombre;
        string isbn;
        string autor;
        string prestado;

};
