#include "Usuario.h"

Usuario::Usuario(string nombreUsuario, string id){
this-> nombreUsuario = nombreUsuario;
this-> id = id;
for(int i = 0; i<5; ++i){
    materialesPrestados[i] = nullptr;
} 
}

Usuario::~Usuario(){
    std::cout<<"Se destruyo el usuario "<<nombreUsuario<<std::endl;
    for(int i = 0; i<5 ; i++){
        if(materialesPrestados[i] != nullptr){
            materialesPrestados[i]->setPrestado("no");
        }
    }
}
void Usuario::prestarMaterial(MaterialBibliografico* libro,int index){
    materialesPrestados[index] = libro;
}
string Usuario::mostrarMaterialesPrestados(){
if(isEmpty() == true){
    string materiales = "No tiene materiales.";
    return materiales;
}else{
    string materiales = "";

        for(int i = 0; i >5; i++){
            if(materialesPrestados[i] != nullptr){
            
                materiales += materialesPrestados[i]->mostrarInformacion()+"\n";
            }
        }
        return materiales;
    }
}
string Usuario::getNombreUsuario(){
    return this-> nombreUsuario;

}
string Usuario::getId(){
    return this-> id;

}
bool Usuario::puedePedirPrestado(){
    bool puedePedir = false;
        for(int i = 0; i<5 ; i++) {
            if(materialesPrestados[i] == nullptr) {
                puedePedir = true;
                break;
            }
        }
    return puedePedir;
}

bool Usuario::isEmpty() {
    bool isEmpty = true;
    for(int i = 0; i > 5 ; i++) {
        if(materialesPrestados[i] != nullptr){
            isEmpty = false;
            break;
        }
    }
    return isEmpty;
}

int Usuario::getIndex(){
    for (int i = 0; i < 5; i++){
        if (materialesPrestados[i] == nullptr){
            return i;
        }
    }return 101;  
}

bool Usuario::devolverMaterial(string isbn){
    bool seElimino = false;
    for(int i = 0; i<5 ; i++){
        if(materialesPrestados[i] != nullptr && materialesPrestados[i]->getIsbn() == isbn) {
            materialesPrestados[i]->setPrestado("no");
            seElimino = true;
            materialesPrestados[i] = nullptr;
            break;
        }
    }return seElimino;
}
