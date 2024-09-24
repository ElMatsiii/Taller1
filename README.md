# Taller1

Taller 1 Estructura De Datos

Integrantes:

Daniela Alejandra Infante Soto, 21.446.602-3, daniela.infante@alumnos.ucn.cl, Paralelo C2
Maximo Andres Sazo Troncoso, 21.654.236-3, maximo.sazo@alumnos.ucn.cl, Paralelo C2

Simulador De Biblioteca Digital
-----------------------------------------------------------------------------------------------------------
Descripción
-----------------------------------------------------------------------------------------------------------
El presente proyecto simula un sistema de gestión de biblioteca que le permite al cliente administrar usuarios y materiales bibliograficos en una biblioteca. El programa ofrece las siguientes opciones: buscar, agregar, prestar y devolver materiales y finalmente gestionar usuarios.
-----------------------------------------------------------------------------------------------------------
## Arquitectura del proyecto
-----------------------------------------------------------------------------------------------------------
Usuarios.txt y Materiales.txt: Archivos de almacenamiento y persistencia de datos, donde se guarda la información de usuarios y materiales (libros o revistas) respectivamente. Cada archivo tiene un formato específico para cada tipo de dato.
``` Usuario.h ``` y ``` Usuario.cpp ```: Archivo header e implementación que definen la clase Usuario, representando a un usuario dentro del sistema.
MaterialBibliografico.h y MaterialBibliografico.cpp: Archivo header e implementación que definen la clase MaterialBibliografico, la cual sirve como base para representar materiales del sistema, como libros y revistas.
Libro.h y Libro.cpp: Archivo header e implementación que definen la clase Libro, una clase que hereda de MaterialBibliografico y representa a un libro.
Revista.h y Revista.cpp: Archivo header e implementación que definen la clase Revista, que también hereda de MaterialBibliografico y representa a una revista.
Sistema.h y Sistema.cpp: Archivo header e implementación que contiene la definición de la clase Sistema, la cual gestiona las funcionalidades generales del sistema y la implementación donde se desarrollan los métodos de la clase.
Main.cpp: Archivo principal encargado de ejecutar el sistema, donde se inicializan y ponen en marcha las funcionalidades principales.
-----------------------------------------------------------------------------------------------------------
Instrucciones de uso
-----------------------------------------------------------------------------------------------------------
Compilar el proyecto -> ``` g++ -g -o main .\MaterialBibliografico.cpp .\Revista.cpp .\Libro.cpp .\Usuario.cpp .\Impresora.cpp .\Sistema.cpp .\Main.cpp ```
ejecutar el archivo -> ``` main.exe ```
-----------------------------------------------------------------------------------------------------------
Funcionalidades
-----------------------------------------------------------------------------------------------------------
Devolver materiales prestados
Prestar materiales a usuarios
Mostrar información de materiales
Agregar materiales bibliograficos al sistema
Gestionar usuarios (agregar, buscar, eliminar)
Buscar materiales por título, autor o ID
-----------------------------------------------------------------------------------------------------------
Opciones del menu
-----------------------------------------------------------------------------------------------------------
1) Agregar material bibliografico
2) Buscar libro por Autor
3) Buscar libro por Titulo
4) Prestar o devolver materiales
5) Gestionar usuarios
6) Mostrar todos los materiales de la biblioteca
7) Cerrar sistema
Dependiendo de la opción que escoja el cliente, este deberá seguir las instrucciones que se muestran en pantalla.
-----------------------------------------------------------------------------------------------------------
Comentarios
----------------------------------------------------------------------------------------------------------
El sistema cuenta con los controles de errores necesarios para cada situación.
La información sobre los objetos que se crean en el main se presentan de la siguiente manera:
Formato Usuarios.txt : NOMBRE DE USUARIO;ID -> Ana Martinez;USR-2023-001
Formato Materiales.txt formato: TITULO;ISBN;AUTOR;PRESTADO;PARAMETRO EXTRA 1;PARAMETRO EXTRA 2;TIPO -> Don Quijote De La Mancha,978-0-12-345678-9,Miguel De Cervantes,si,1605,Las aventuras del ingenioso hidalgo don quijote y su fiel escudero sancho panza,libro
