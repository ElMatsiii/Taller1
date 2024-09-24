#pragma once
#include "MaterialBibliografico.h"
class Libro : public MaterialBibliografico{
    
    protected:
    string fechaPublicacion;
    string resumen;
    
    public:
    Libro(string nombre, string isbn, string autor, string prestado,string fechaPublicacion,string resumen);
    string mostrarInformacion() override;
    string getFechaPublicacion();
    string getResumen();
    ~Libro();
    void setFechaPublicacion(string fechaPublicacion);
    void setResumen(string resumen);
};