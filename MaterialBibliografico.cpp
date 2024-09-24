#include <iostream>
#include <string>
#include "MaterialBibliografico.h"

    MaterialBibliografico::MaterialBibliografico(std::string nombre,std::string isbn,std::string autor,std::string prestado) {//constructor
        this->nombre = nombre;
        this->isbn = isbn;
        this->autor = autor;
        this->prestado = prestado;
    }
    std::string MaterialBibliografico::mostrarInformacion() {//funcion mostrar info
        return "Nombre: "+this->nombre+"\nIsbn: "+this->isbn+"\nAutor: "+this->autor+"\nPrestado: "+this->prestado;
    }
    MaterialBibliografico::~MaterialBibliografico(){//destructor
        //std::cout << "Se ha destruido "+this->nombre << std::endl;
    }
    string MaterialBibliografico::getNombre(){
        return this->nombre = nombre;
    }
    string MaterialBibliografico::getIsbn(){
        return this->isbn = isbn;
    }
    string MaterialBibliografico::getAutor(){
        return this->autor = autor;
    }
    string MaterialBibliografico::getPrestado(){
        return this->prestado = prestado;
    }
    void MaterialBibliografico::setPrestado(string a){
        this-> prestado = a;
        if(prestado=="no") {
        std::cout<<"Se devolvio el material con isbn "+isbn<<std::endl;
        }
    }
    
