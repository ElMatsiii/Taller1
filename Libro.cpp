#include "Libro.h"

Libro::Libro(string nombre, string isbn, string autor, string prestado,string fechaPublicacion,string resumen)//constructor de libro
    :MaterialBibliografico(nombre,isbn,autor,prestado)/**esto vendria a ser el super(la herencia de los parametros del padre), pero tiene que estar antes de las llaves {}**/{
    this->fechaPublicacion = fechaPublicacion;
    this->resumen = resumen;
}
string Libro::mostrarInformacion(){//la funcion heredada de MaterialBibliografico
    string texto = "";//para contatenar el texto
    texto += MaterialBibliografico::mostrarInformacion();
    texto += "\nFecha de publicacion: "+this->fechaPublicacion+"\nResumen:"+this->resumen;
    return texto;
}
Libro::~Libro() {
    std::cout<<"Se destruyo el libro "<< nombre << std::endl;
}
string Libro::getFechaPublicacion(){
    return this-> fechaPublicacion;
}
string Libro::getResumen(){
    return this-> resumen;
}
void Libro::setFechaPublicacion(string fechaPublicacion){
    this->fechaPublicacion = fechaPublicacion;
}
void Libro::setResumen(string resumen){
    this->resumen = resumen;
}