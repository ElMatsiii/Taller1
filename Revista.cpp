#include "Revista.h"

Revista::Revista(string nombre, string isbn, string autor, string prestado, string numeroEdicion, string mesPublicacion)
:MaterialBibliografico(nombre, isbn, autor, prestado){
    this-> numeroEdicion = numeroEdicion;
    this-> mesPublicacion  = mesPublicacion;
    
}
string Revista::mostrarInformacion(){
    string texto = "";
    texto += MaterialBibliografico::mostrarInformacion();
    texto += "\nnumeroEdicion: "+this->numeroEdicion+"\nmesPublicacion:"+this->mesPublicacion;
    return texto;
}
string Revista::getNumeroEdicion(){
    return this-> numeroEdicion = numeroEdicion;
}
string Revista::getMesPublicacion(){
    return this-> mesPublicacion = mesPublicacion;
}
Revista::~Revista(){
    std::cout<<"Se destruyo la revista "<< nombre << std::endl;
}