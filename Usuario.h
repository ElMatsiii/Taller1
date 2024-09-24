#pragma once
#include "MaterialBibliografico.h"
#include <string>
using namespace std;
class Usuario{
protected:
    string nombreUsuario;
    string id;
    MaterialBibliografico* materialesPrestados[5];

public:
    Usuario(string nombreUsuario, string id);
    ~Usuario();
    void prestarMaterial(MaterialBibliografico* libro,int index);
    string mostrarMaterialesPrestados();
    string getNombreUsuario();
    int getIndex();
    bool puedePedirPrestado();
    bool isEmpty();
    string getId();
    bool devolverMaterial(string isbn);

    
};
