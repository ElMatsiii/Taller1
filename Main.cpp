#include <iostream>
#include <limits>
#include <fstream>
#include "Sistema.h"
using namespace std;
//asda    

void lecturaArchivoUsuarios(Sistema* sistema);
void lecturaArchivoMateriales(Sistema* sistema);
int main() {
    Sistema* sistema = new Sistema();
    lecturaArchivoUsuarios(sistema);
    lecturaArchivoMateriales(sistema);
    int op = 0;
    do {
        
        cout << "**********Sistema**********" << endl;
        cout << "1) Agregar material bibliografico" << endl; //
        cout << "2) Buscar libro por Autor" << endl;    //
        cout << "3) Buscar libro por Titulo" << endl;   //
        cout << "4) Prestar o devolver materiales" << endl;    
        cout << "5) Gestionar usuarios" << endl;     //
        cout << "6) Mostrar todos los materiales de la biblioteca" << endl;     //
        cout << "7) Cerrar sistema" << endl;    //
        cout << "**********Sistema**********" << endl;
        cout << "Ingresa la opcion que desea realizar (1/2/3/4/5/6/7)" << endl;
        cin >> op;
        while (op < 1 || op > 7 || op == NULL)
        {
            cout<<"Ingrese una opcion valida (1/2/3/4/5/6/7):"<<endl;
            cin >> op;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(op == 1){
            if (sistema->espacioBiblioteca() == true){
                string nombre;
                string isbn;  
                string autor;
                string prestamo;
                string aux1;
                string aux2;
            
                std::cout << "Que desea agregar:\n1)Libro\n2)Revista" << std::endl;
                cin>> op;
                while (op < 1 || op > 2 || op == NULL)
                {
                    cout<<"Ingrese una opcion valida (1/2):"<<endl;
                    cin >> op;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<< "Ingrese el nombre:" <<endl;
                getline(cin,nombre);
                while (nombre.empty() == true)
                {
                    cout<<"Ingrese un nombre:"<<endl;
                    getline(cin,nombre);
                }
                cout<< "Ingrese el isbn:" <<endl;
                getline(cin,isbn);
                while(sistema->existeMaterial(isbn) == true){
                    cout<<"El material ya existe, ingresar un isbn distinto:"<<endl;
                    getline(cin,isbn);
                }
                cout<< "Ingrese el autor:" <<endl;
                getline(cin,autor);
                while (autor.empty() == true)
                {
                    cout<<"Ingrese un autor:"<<endl;
                    getline(cin,autor);
                }
                cout<< "Estado de prestamo(si/no):" <<endl;
                getline(cin,prestamo);
                while (prestamo != "si" && prestamo != "no" || prestamo.empty() == true){
                    cout<< "Estado invalido, vuelva a ingresar el estado de prestamo(si/no):" <<endl;
                    getline(cin,prestamo);
                }
                
            
                if(op == 1){
                    std::cout << "Ingrese la fecha de publicacion(DD/MM/AA):" << std::endl;
                    getline(cin,aux1);
                    while (aux1.empty() == true){
                        cout<<"Ingrese una fecha de publicacion(DD/MM/AA):"<<endl;
                        getline(cin,aux1);
                    }
                    std::cout << "Ingrese el resumen:" << std::endl;
                    getline(cin,aux2);
                    while (aux2.empty() == true){
                        cout<<"Ingrese un resumen:"<<endl;
                        getline(cin,aux2);
                    }
                    cout<<sistema->crearMaterialBibliografico(nombre,isbn,autor,prestamo,aux1,aux2,"libro")<<endl;
                    sistema->aniadirTextoMateriales("Materiales.txt",nombre,isbn,autor,prestamo,aux1,aux2,"libro");//funcion para aniadir los libros al archivo de texto
                }else if(op == 2){
                    std::cout << "Ingrese el numero de edicion:" << std::endl;
                    getline(cin,aux1);
                    while (aux1.empty() == true){
                        cout<<"Ingrese un numero de edicion:"<<endl;
                        getline(cin,aux1);
                    }
                    std::cout << "Ingrese el mes de publicacion:" << std::endl;
                    getline(cin,aux2);
                    while (aux2.empty() == true){
                        cout<<"Ingrese un mes de publicacion:"<<endl;
                        getline(cin,aux2);
                    }
                    cout<<sistema->crearMaterialBibliografico(nombre,isbn,autor,prestamo,aux1,aux2,"revista")<<endl;
                    sistema->aniadirTextoMateriales("Materiales.txt",nombre,isbn,autor,prestamo,aux1,aux2,"revista");//aqui escribe para aniadir las revistas
                }
            }else{
                cout << "No hay espacio en la biblioteca." << endl;
            }
            
        }else if(op == 2){
            string autor;
            cout<<"Ingrese el Autor del libro:"<<endl;
            getline(cin,autor);
            while (autor.empty() == true){
                cout<<"Ingrese un Autor:"<<endl;
                getline(cin,autor);
            }
            cout<<sistema->buscarMaterial(autor,"")<<endl;
            
        }else if(op == 3){
            string titulo;
            cout<<"Ingrese el Titulo del libro:"<<endl;
            getline(cin,titulo);
            while (titulo.empty() == true){
                cout<<"Ingrese el Titulo:"<<endl;
                getline(cin,titulo);
            }
            cout<<sistema->buscarMaterial("",titulo)<<endl;
            
        }else if(op == 4){
            string nombreUsuario = "";
            string isbn = "";
            std::cout << "Que desea hacer:\n1)Solicitar un material\n2)Devolucion de material" << std::endl;
            cin>> op;
            while (op< 1  || op > 2 || op == NULL){
                cout<<"Ingrese una opcion valida:\n1)Solicitar un material\n2)Devolucion de material"<<endl;
                cin>> op;
            }
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(op == 1){
                cout<<"Ingrese el Isbn:"<<endl;
                getline(cin,isbn);
                while(isbn.empty()){
                    cout<<"Ingrese un isbn valido:"<<endl;
                    getline(cin,isbn);
                }
                while(sistema->existeMaterial(isbn) == false){
                    cout<<"El material no existe. Ingrese un isbn valido:"<<endl;
                    getline(cin,isbn);
                }                                   
                while ((sistema->esMaterialPrestado(isbn) == true && sistema->existeMaterial(isbn) == true) || (sistema->existeMaterial(isbn) == false)){
                    cout<<"El material solicitado no esta disponible. Ingrese otro isbn:"<<endl;
                        getline(cin,isbn);
                    while(isbn.empty()){
                        cout<<"Ingrese un isbn valido:"<<endl;
                        getline(cin,isbn);
                    }
                }
                string ID = "";
                cout<<"El material esta disponible, cual es su ID de usuario?"<<endl;
                getline(cin,ID);
                while(ID.empty() == true){
                    cout<<"Ingrese un ID de usuario:"<<endl;
                    getline(cin,ID);
                }
                if(sistema-> existeUsuario(ID) == false){
                    cout<<"No existe el usuario. Ingresar el nombre del usuario para crearlo:"<<endl;
                    getline(cin, nombreUsuario);
                    while (nombreUsuario.empty() == true){
                        cout<<"Ingrese un nombre del usuario:"<<endl;
                        getline(cin, nombreUsuario);
                    }
                    cout<<sistema->crearUsuario(nombreUsuario, ID)<<endl;
                    sistema->aniadirTextoUsuarios("Usuarios.txt",nombreUsuario,ID);
                    cout<<sistema->hacerPrestamo(ID, isbn)<<endl;
                }else{
                    if(sistema->usuarioPuedePedir(ID) == false){
                        cout<<"El usuario no puede pedir mas materiales."<<endl;
                    }else{
                        cout<<sistema->hacerPrestamo(ID,isbn)<<endl;
                    }
                }
            
            
            }else if(op == 2){
                cout<<"Ingrese el Isbn:"<<endl;
                getline(cin,isbn);
                while (isbn.empty() == true){
                    cout<<"Ingrese un Isbn:"<<endl;
                    getline(cin,isbn);
                }
                if(sistema->esMaterialPrestado(isbn) == true){
                    string ID = "";
                    cout<<"Cual es su ID de usuario?"<<endl;
                    getline(cin,ID);
                    while (ID.empty() == true)
                    {
                        cout<<"Ingrese su ID de usuario:?"<<endl;
                        getline(cin,ID);
                    }
                    
                    cout<<sistema->eliminarMaterial(isbn, ID)<<endl;
                }else{
                    cout<<"El material no esta designado a ningun usuario."<<endl;
                }
            }    
            
        }else if(op == 5){
            string nombreUsuario = "";
            string id = "";
            std::cout << "Que desea hacer:\n1)Crear usuario\n2)Buscar usuario\n3)Eliminar usuario" << std::endl;
            cin>> op;
            while (op < 1 || op > 3 || op == NULL)
            {
                std::cout << "Ingrese una opcion valida:\n1)Crear usuario\n2)Buscar usuario\n3)Eliminar usuario" << std::endl;
                cin>> op;
            }
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(op == 1){
                cout<<"Ingrese el nombre:"<<endl;
                getline(cin,nombreUsuario);
                while (nombreUsuario.empty() == true){
                    cout<<"Ingrese el nombre:"<<endl;
                    getline(cin,nombreUsuario);
                }
                cout<<"Ingrese el id:"<<endl;
                getline(cin, id);
                while (id.empty() == true){
                    cout<<"Ingrese un id:"<<endl;
                    getline(cin, id);
                }
                
                cout<<sistema->crearUsuario(nombreUsuario, id)<<endl;//aqui se crea un nuevo usuario
                sistema->aniadirTextoUsuarios("Usuarios.txt",nombreUsuario,id);
            }
            else if(op == 2) {
                cout<<"Ingrese ID:"<<endl;
                getline(cin, id);
                while (id.empty() == true){
                    cout<<"Ingrese ID:"<<endl;
                    getline(cin, id);
                }
                cout<<sistema->buscarUsuarioPorId(id)<<endl;
            }
            else if(op == 3) {
                cout<<"Ingrese ID del usuario a eliminar:"<<endl;
                getline(cin, id);
                while (id.empty() == true){
                    cout<<"Ingrese ID del usuario a eliminar:"<<endl;
                    getline(cin, id);
                }
                sistema->eliminarUsuarioPorId(id);

            }   
        }else if(op == 6){
            cout<<sistema->mostrarTodo()<<endl;
        }
        
    }while(op != 7);
    string opcion = "";
    cout<<"Desea actualizar los datos en los archivos de texto antes de cerrar sistema(si/no)?"<<endl;
    getline(cin, opcion);
    while (opcion == "" || (opcion != "si" && opcion != "no"))
    {
        cout<<"Ingreso invalido. Desea actualizar los datos antes de cerrar sistema en el txt (si/no)?"<<endl;
        getline(cin, opcion);
    }
    
    if(opcion == "si"){
        cout<<sistema->actualizarDatos("Materiales.txt","Usuarios.txt")<<endl;
    }

    delete sistema;
    cout << "Cerrando sistema..." << endl;
    cout << "Sistema cerrado." << endl;
    
    return 0;
}
void lecturaArchivoUsuarios(Sistema* sistema){

     ifstream Usuarios("Usuarios.txt");  // Abrir el archivo
    
    if (!Usuarios.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return;
    }

    string linea;
    while (std::getline(Usuarios, linea) && linea  != "") {

        // Procesar cada línea para obtener el nombre y el ID
        string* datos = sistema->procesarLineaUsuario(linea);

        cout<<sistema->crearUsuario(datos[0],datos[1])<<endl;
    }

    Usuarios.close();  // Cerrar el archivo
}
void lecturaArchivoMateriales(Sistema* sistema){

     ifstream archivo("Materiales.txt");  // Abrir el archivo 
    
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return;
    }

    string linea;
    while (std::getline(archivo, linea) && linea  != "") {

        // Procesar cada línea para obtener los atributos de los materiales de la siguiente manera:
        // nombre, isbn, autor, prestado, parametro1, parametro2, tipo de material
        string* datos = sistema->procesarLineaMateriales(linea);
        cout<<sistema->crearMaterialBibliografico(datos[0],datos[1],datos[2],datos[3],datos[4],datos[5],datos[6])<<endl;
    }
    archivo.close();  // Cerrar el archivo
} 
