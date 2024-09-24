#pragma once
#include "MaterialBibliografico.h"

class Revista : public MaterialBibliografico {
    
    protected:
    string numeroEdicion;
    string mesPublicacion;
    
    public:
    Revista(string nombre, string isbn, string autor, string prestado, string numeroEdicion, string mesPublicacion);
    string mostrarInformacion() override;
    string getNumeroEdicion();
    string getMesPublicacion();
    ~Revista();
};