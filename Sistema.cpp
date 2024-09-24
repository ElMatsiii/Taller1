#include "Sistema.h"
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int contMaterial = 0;
int contUsuario = 0;

MaterialBibliografico* biblioteca[100];//lista para almacenar los materiales bibliograficos
Usuario* usuarios[100];//lista para almacenar los usuarios


Sistema::Sistema(){}//constructor del sistema

//Crea materiales utilizando los atributos que se ingresen por el menu.
string Sistema::crearMaterialBibliografico(string nombre,string isbn,string autor,string prestamo,string extra1,string extra2,string tipo){//funcion para crear materiales
    
    if(tipo == "libro"){
        MaterialBibliografico* material =  new Libro(nombre,isbn,autor,prestamo,extra1,extra2);
        biblioteca[contMaterial] = material;
        contMaterial++;
     }else if(tipo == "revista"){
        MaterialBibliografico* material =  new Revista(nombre,isbn,autor,prestamo,extra1,extra2);
        biblioteca[contMaterial] = material;
        contMaterial++;
     };

     return "se ha creado  el material: "+nombre+" con isbn: "+isbn;

}

//Busca materiales en la lista que contiene los materiales.
string Sistema::buscarMaterial(string autor,string titulo){
    
    if(autor != ""){//recorre la lista buscando un material por el autor
        for (int i = 0; i < contMaterial; i++) {
            if(biblioteca[i]->getAutor() == autor){
                return biblioteca[i]->mostrarInformacion();
            }   
        }
    }else if(titulo != ""){//recorre la lista buscando un material por el titulo
        for (int i = 0; i < contMaterial; i++) {
            if(biblioteca[i]->getNombre() == titulo){
                return biblioteca[i]->mostrarInformacion();
            }   
        }
    }
    return "";
}

//Verifica que el material exista dentro de la lista de biblioteca.
bool Sistema::esMaterialPrestado(string isbn){ 
    bool prestado = true;

    for (int i = 0; i < contMaterial; i++) {
        if(biblioteca[i]->getIsbn() == isbn){               
            if (biblioteca[i]->getPrestado() == "no"){  
                prestado = false;
                break;
            }  
        }
    }
    return prestado;
}

//Destructor del sistema.
Sistema::~Sistema(){  //destructor
    for (int i = 0; i < contMaterial; i++){
            delete biblioteca[i];
            biblioteca[i] = nullptr;
            delete usuarios[i];
            usuarios[i] = nullptr;
    }
    std::cout << "Se ha destruido el sistema, los usuarios y materiales." << std::endl;

}

//Crea el usuario con sus respectivos atributos.
string Sistema::crearUsuario(string nombreUsuario, string id) {
    string text = "";
    Usuario* usuario = new Usuario(nombreUsuario, id);
    usuarios[contUsuario] = usuario;
    contUsuario++;
    text = "Se ha creado el usuario " + nombreUsuario + " con el id " + id;
    return text;

}

//Busca el id del usuario en la lista de usuarios.
string Sistema::buscarUsuarioPorId(string id) {
    string texto = "No existe el usuario.";
    for(int i = 0; i < contUsuario; i++) {
        if(usuarios[i] != nullptr && usuarios[i]->getId() == id){
            texto = "nombre: "+usuarios[i]->getNombreUsuario()+"\n"+usuarios[i]->mostrarMaterialesPrestados();
            break;
        }
    }
    return texto;
}

//Elimina usuarios segun el id.
void Sistema::eliminarUsuarioPorId(string id) {
    for(int i = 0; i < contUsuario; i++) {
        if(usuarios[i] != nullptr && usuarios[i]->getId() == id){
            delete usuarios[i];
            usuarios[i] = nullptr;
            break;
        }
    }
}

//Verifica si existe el usuario ingresado.
bool Sistema::existeUsuario(string id){
    bool existe = false;
    for (int i = 0; i < contUsuario; i++){
        if (usuarios[i]->getId() ==  id){
            existe = true;
            return existe;
        }
    }
    return existe;
}

//Verifica si el usuario puede pedir prestado otro material.
bool Sistema::usuarioPuedePedir(string id){
    bool puede = true;
    for(int i = 0; i < contUsuario; i++) {
        if(usuarios[i]->getId() == id){
            if(usuarios[i]->getIndex() == 101){
            puede = false;
            }
        }
    }return puede;
}

//Realiza la petición de materiales y los asigna a cada usuario correspondiente.
string Sistema::hacerPrestamo(string id,string isbn){
    string text = "";
    for (int i = 0; i < contUsuario; i++){
        if (usuarios[i] != nullptr){
            int espacioLibre = usuarios[i]->getIndex();   
            for (int j = 0; j < contMaterial; j++){
                if (usuarios[i] != nullptr && biblioteca[j] != nullptr){
                    if (usuarios[i]->getId() == id && biblioteca[j]->getIsbn() == isbn){
                        usuarios[i]->prestarMaterial(biblioteca[j],espacioLibre);
                        biblioteca[j]->setPrestado("si");
                        text = "El usuario "+usuarios[i]->getNombreUsuario()+" ha pedido el material con isbn "+biblioteca[j]->getIsbn();
                        return text;
                    }    
                }
            }
        }
    }
    return text;
}

//Elimina materiales de los respectivos usuarios y notifica en caso de no existir el material.
string Sistema::eliminarMaterial(string isbn, string id) {
    string texto = "No se encontro el material.";
    for(int i = 0; i < contUsuario; i++) {
        if(usuarios[i] != nullptr && usuarios[i]->getId() == id){
            if(usuarios[i]->devolverMaterial(isbn) == true){
                texto = "Se elimino exitosamente el material con isbn "+isbn;
            }
        }  
    }return texto; 
}

//Verifica si existe el material segun su isbn.
bool Sistema::existeMaterial(string isbn){
    bool existe = false;
    for (int i = 0; i < contMaterial; i++){
        if (biblioteca[i]->getIsbn() == isbn && biblioteca[i] != nullptr){
            existe = true;
            return existe;
        }
    }
    return existe;
}

//Muestra todos los materiales de la biblioteca.
string Sistema::mostrarTodo(){
    string txt = "";
    cout<<"1"<<endl;
    for(int i = 0; i<contMaterial; i++){
        txt += "\nMaterial "+to_string(i+1)+"\n";
        txt += biblioteca[i]->mostrarInformacion()+"\n";
    }
    return txt;
}

//Verifica si la biblioteca tiene espacio para mas material.
bool Sistema::espacioBiblioteca(){
    bool espacio = true;
    for (int i = 0; i < 100; i++){
        if (biblioteca[i] != nullptr){
            espacio = false;
        }else{
            espacio = true;
            break;
        }
    }
    return espacio;
}
// Función para separar el nombre y el ID usando la coma como delimitador
string* Sistema::procesarLineaUsuario(string& linea) {
    static string datos[2];  // Array estático para nombre e ID
    
    size_t pos = linea.find(',');  // Encontrar la posición de la coma

    if (pos != string::npos) {
        datos[0] = linea.substr(0, pos);           // Primer parte: el nombre
        datos[1] = linea.substr(pos + 1);          // Segunda parte: el ID (después de la coma)
    }
    
    return datos;  // Devolver el array estático
}  
string* Sistema::procesarLineaMateriales(string& linea) {
    static std::string datos[7];  // Array estático para 6 atributos
    size_t inicio = 0;
    size_t pos = 0;
    int indice = 0;

    // Bucle para encontrar las comas y extraer cada atributo
    while ((pos = linea.find(',', inicio)) != std::string::npos && indice < 6) {
        datos[indice++] = linea.substr(inicio, pos - inicio);            // Extraer el atributo
        inicio = pos + 1;  // Actualizar el inicio para la próxima búsqueda
    }

    // Último atributo después de la última coma
    datos[indice] = linea.substr(inicio);
    
    return datos;  // Devolver el array estático con los 6 atributos
}

//funcion para escribir en el archivo Materiales.txt los nuevos materiales creados
void Sistema::aniadirTextoMateriales(string texto,string nombre,string isbn,string autor,string prestado,string extra1,string extra2,string tipo)
{
    ofstream archivo;
    archivo.open(texto,ios::app);//abre el archivo en modo append,  para agregar texto al final del archivo


    if (archivo.fail())
    {
        cout<<"No se ha podido abrir el archivo."<<endl;//control de error en caso de no encuentre el archivo
        exit(1);
    }
    
    archivo<<nombre+","+isbn+","+autor+","+prestado+","+extra1+","+extra2+","+tipo<<endl;//esto escribe  el texto en el archivo y finaliza saltandose una linea


}

//funcion para escribir en el archivo Usuarios.txt los nuevos usuarios creados
void Sistema::aniadirTextoUsuarios(string texto,string nombre,string id)
{
    ofstream archivo;
    archivo.open(texto,ios::app);//abre el archivo en modo append,  para agregar texto al final del archivo


    if (archivo.fail())
    {
        cout<<"No se ha podido abrir el archivo."<<endl;//control de error en caso de no encuentre el archivo
        exit(1);
    }
    
    archivo<<nombre+","+id<<endl;//esto escribe  el texto en el archivo y finaliza saltandose una linea

}

//función que actualiza los datos en los archivos de texto.
string Sistema::actualizarDatos(string txt1, string txt2){
    ofstream archivo(txt1); 

    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo para escritura."<<endl;
        exit(1);
    }

    for(int i = 0; i<100; i++){
        if(biblioteca[i] != nullptr){
            archivo<<biblioteca[i]->getNombre()+","+biblioteca[i]->getIsbn()+","+biblioteca[i]->getAutor()+","+biblioteca[i]->getPrestado();

            Libro* libro = dynamic_cast<Libro*>(biblioteca[i]);
            if(libro != nullptr){
                archivo<< ","+libro->getFechaPublicacion()+","+libro->getResumen()+",libro";
            } else {
                Revista* revista = dynamic_cast<Revista*>(biblioteca[i]);
                if(revista != nullptr){
                    archivo<<","+revista->getNumeroEdicion()+","+revista->getMesPublicacion()+",revista";
                }
            }
        archivo << std::endl;
        }
    }
    archivo.close();

    ofstream archivo2(txt2);

    if(!archivo2.is_open()){
        cout<<"No se pudo abrir el archivo para escritura."<<endl;
        exit(1);
    }

     for(int i = 0; i<100; i++){
        if(usuarios[i] != nullptr){
            archivo2<<usuarios[i]->getNombreUsuario()+","+usuarios[i]->getId()<<endl;
        }
    }
    archivo2.close();
    return "Se actualizaron correctamente los archivos de texto.";
}