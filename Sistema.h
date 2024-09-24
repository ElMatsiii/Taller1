#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Sistema{
    
    public:
        Sistema();//constructor
        string crearMaterialBibliografico(string nombre,string isbn,string autor,string prestamo,string extra1,string extra2,string tipo);//funcion para crear material
        string buscarMaterial(string autor,string titulo);//funcion para buscar material
        bool esMaterialPrestado(string isbn);//funcion para buscar material por isbn 
        ~Sistema();//destructor
        string crearUsuario(string nombreUsuario, string id);
        string buscarUsuarioPorId(string id);
        bool existeUsuario(string id);
        void eliminarUsuarioPorId(string id);
        bool usuarioPuedePedir(string id);
        bool existeMaterial(string isbn);
        string hacerPrestamo(string id,string isbn);
        string eliminarMaterial(string isbn, string id);
        string mostrarTodo();
        bool espacioBiblioteca();
        string* procesarLineaUsuario(string& linea);
        string* procesarLineaMateriales(string& linea);
        void aniadirTextoMateriales(string archivo,string nombre,string isbn,string autor,string prestado,string extra1,string extra2,string tipo);
        void aniadirTextoUsuarios(string archivo, string nombre, string id);
        string actualizarDatos(string txt1, string txt2);
};