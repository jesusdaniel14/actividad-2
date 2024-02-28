#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

int randomico(int max) {
	return rand() % max;
}

// Estructura para datos de tiempo
struct Tiempo {
	int dia;
	int mes;
	int anio;
};

// Estructura para libros
struct Libro {
	int snbi;
	string tituloLibro;
	string autorLibro;
	Tiempo fechaPublicacion;
};

// Función para llenar datos de libros
void llenar(int cad, Libro vt[],string titulos[],string autores[]) {
	for (int i = 0; i < cad; i++) {
		vt[i].snbi = i + 1;
		vt[i].tituloLibro = titulos[i];
		vt[i].autorLibro = autores[i];
		vt[i].fechaPublicacion.dia = randomico(31) + 1;
		vt[i].fechaPublicacion.mes = randomico(12) + 1;
		vt[i].fechaPublicacion.anio = randomico(20) + 2000;
	}
}

// Función para imprimir detalles de libros
void imprimir(const Libro vt[], int cad, int index) {
	if (index < cad) {
		cout << "SNBI:  " << vt[index].snbi << endl;
		cout << "Titulo: " << vt[index].tituloLibro << endl;
		cout << "Autor: " << vt[index].autorLibro << endl;
		cout << "Fecha de publicacion: " << vt[index].fechaPublicacion.dia << "/"
			<< vt[index].fechaPublicacion.mes << "/"
			<< vt[index].fechaPublicacion.anio << endl;
		cout << endl;
		
		imprimir(vt, cad, index + 1); // Llamada recursiva para el siguiente libro
	}
}

// Estructura para datos de usuario
struct Usuario {
	int idUsuario;
	string nombre;
	string apellido;
	string contrasena;
};

// Función para generar nombres aleatorios
string generarNombre(int longitud) {
	const string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string nombre;
	for (int i = 0; i < longitud; ++i) {
		nombre += caracteres[randomico(caracteres.length())];
	}
	return nombre;
}

// Función para generar apellidos aleatorios
string generarApellido(int longitud) {
	const string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string apellido;
	for (int i = 0; i < longitud; ++i) {
		apellido += caracteres[randomico(caracteres.length())];
	}
	return apellido;
}

// Función para llenar datos de usuarios
void llenar(Usuario& usuario, int id, int longitudNombre, int longitudApellido, int cad) {
	
	usuario.idUsuario = id;
	usuario.nombre = generarNombre(longitudNombre);
	usuario.apellido = generarApellido(longitudApellido);
	usuario.contrasena = usuario.nombre + usuario.apellido; // Concatenación de nombre y apellido
	
}

// Función para imprimir detalles de usuarios
void imprimir(const Usuario& usuario, int cad, int index) {
	if (index < cad) {
		cout << "ID Usuario:  " << usuario.idUsuario << endl;
		cout << "Nombre: " << usuario.nombre << endl;
		cout << "Apellido: " << usuario.apellido << endl;
		cout << "Contraseña: " << usuario.contrasena << endl;
		cout << "" << endl;
		// Adicionar 1 atributo.
		imprimir(usuario, cad, index + 1); // Llamada recursiva para el siguiente usuario
	}
}

// Estructura para datos de empleados
struct Empleado {
	int idEmpleado;
	string nombre;
	string apellido;
	string email;
};

// Función para llenar datos de empleados
void llenar(Empleado& empleado, int id, int longitudNombre, int longitudApellido, int cad) {
	
	empleado.idEmpleado = id;
	empleado.nombre = generarNombre(longitudNombre);
	empleado.apellido = generarApellido(longitudApellido);
	empleado.email = empleado.nombre + empleado.apellido; // Concatenación de nombre y apellido
	
}

// Función para imprimir detalles de empleados
void imprimir(const Empleado& empleado, int cad, int index) {
	if (index < cad) {
		cout << "ID Usuario:  " << empleado.idEmpleado << endl;
		cout << "Nombre: " << empleado.nombre << endl;
		cout << "Apellido: " << empleado.apellido << endl;
		cout << "Email: " << empleado.email << "@gmail.com" << endl;
		cout << "" << endl;
		// Adicionar 1 atributo.
		imprimir(empleado, cad, index + 1); // Llamada recursiva para el siguiente empleado
	}
}

// Función para buscar libros repetidos por título
void buscar_repetidos(const Libro vt[], int cad, const string& titulo, int index) {
	if (index < cad) {
		if (vt[index].tituloLibro == titulo) {
			cout << "Libro repetido encontrado:" << endl;
			imprimir(vt, cad, index);
		}
		buscar_repetidos(vt, cad, titulo, index + 1);
	}
}

// Función para buscar un libro por título
int buscar(const Libro vt[], int cad, const string& titulo, int index) {
	if (index < cad) {
		if (vt[index].tituloLibro == titulo) {
			buscar_repetidos(vt, cad, titulo, index + 1);
			return index; // Retorna el índice del libro si se encuentra
		} else {
			return buscar(vt, cad, titulo, index + 1); // Llamada recursiva para el siguiente libro
		}
	}
	return -1; // Retorna -1 si el libro no se encuentra
}

// Función para buscar usuarios repetidos por nombre
void buscar_repetidos(const Usuario usuario[], int cad, const string& nombre, int index,int repetido) {
	if (index < cad) {
		if (usuario[index].nombre == nombre) {
			repetido++;
			if (repetido == 1) {
				cout << "Usuario repetido encontrado:" << endl;
			}
			imprimir(usuario[index], cad, index);
		}
		buscar_repetidos(usuario, cad, nombre, index + 1,repetido);
	}
}

// Función para buscar un usuario por nombre
int buscar(const Usuario usuario[], int cad, const string& nombre, int index) {
	if (index < cad) {
		if (usuario[index].nombre == nombre) {
			int repetido = 0;
			buscar_repetidos(usuario, cad, nombre, index + 1,repetido);
			return index; // Retorna el índice del usuario si se encuentra
		} else {
			return buscar(usuario, cad, nombre, index + 1); // Llamada recursiva para el siguiente usuario
		}
	}
	return -1; // Retorna -1 si el usuario no se encuentra
}

// Función para buscar empleados repetidos por nombre
void buscar_repetidos(const Empleado empleado[], int cad, const string& nombre, int index) {
	if (index < cad) {
		if (empleado[index].nombre == nombre) {
			cout << "Empleado repetido encontrado:" << endl;
			imprimir(empleado[index], cad, index);
		}
		buscar_repetidos(empleado, cad, nombre, index + 1);
	}
}

// Función para buscar un empleado por nombre
int buscar(const Empleado empleado[], int cad, const string& nombre, int index) {
	if (index < cad) {
		if (empleado[index].nombre == nombre) {
			buscar_repetidos(empleado, cad, nombre, index + 1);
			return index; // Retorna el índice del empleado si se encuentra
		} else {
			return buscar(empleado, cad, nombre, index + 1); // Llamada recursiva para el siguiente empleado
		}
	}
	return -1; // Retorna -1 si el empleado no se encuentra
}

// Función para el menú principal
int menu(Libro vt[], int cad, Usuario& usuario, Empleado& empleado, 
		 int longitudNombre, int longitudApellido, const string& titulo, 
		 const string& nombre, int index,string titulos[],string autores[]) {
	while (true) {
		cout << "\nMENU" << endl;
		cout << "1. Llenar datos" << endl;
		cout << "2. Listado" << endl;
		cout << "3. Busqueda" << endl;
		cout << "4. Salir" << endl;
		
		int opcion;
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			llenar(cad, vt, titulos,autores);
			llenar(usuario, 1, longitudNombre, longitudApellido, cad);
			llenar(empleado, 1, longitudNombre, longitudApellido, cad);
			cout<<"Datos llenados"<<endl;
			break;
		case 2:
			while (true) {
				cout << "\nSUBMENU LISTADO" << endl;
				cout << "1. Listado de libro" << endl;
				cout << "2. Listado de Usuario" << endl;
				cout << "3. Listado de Bibliotecario" << endl;
				cout << "4. Salir" << endl;
				
				int opcion;
				cout << "Seleccione una opción: ";
				cin >> opcion;
				switch (opcion) {
				case 1:
					imprimir(vt, cad, 0);
					break;
				case 2:
					imprimir(usuario, cad, 0+1);
					break;
				case 3:
					imprimir(empleado, cad, 0+1);
					break;
				case 4:
					return 0;
				default:
					cout << "Opción no válida. Intente de nuevo." << endl;
				}
			}
			break;
		case 3:
			while (true) {
				cout << "\nSUBMENU BUSQUEDA" << endl;
				cout << "1. Buscar libro" << endl;
				cout << "2. Buscar Usuario" << endl;
				cout << "3. Buscar Bibliotecario" << endl;
				cout << "4. Salir" << endl;
				
				int opcion;
				cout << "Seleccione una opción: ";
				cin >> opcion;
				switch (opcion) {
				case 1:
				{
					string titulo_a_buscar;
					cout << "Ingrese el título del libro a buscar: ";
					cin >> titulo_a_buscar;
					int indice_libro = buscar(vt, cad, titulo_a_buscar,0);
					if (indice_libro != -1) {
						cout << "Libro encontrado:" << endl;
						imprimir(vt, cad, indice_libro);
						
					} else {
						cout << "Libro no encontrado." << endl;
					}
				}
				break;
				case 2:
				{
					//	string nombre_a_buscar;
					//	string buscador;
					//	cout << "Ingrese el nombre del usuario a buscar: ";
					//	cin >> nombre_a_buscar;
					//	int indice_usuario = buscar(usuario, cad, nombre_a_buscar);
					//	if (indice_usuario != -1) {
					//		cout << "Usuario encontrado:" << endl;
					//		imprimir(usuario, cad, indice_usuario);
					//	} else {
					cout << "Usuario no encontrado." << endl;
					//	}
				}
				break;
				case 3:
				{
					//	string nombre_a_buscar;
					//	cout << "Ingrese el nombre del bibliotecario a buscar: ";
					//	cin >> nombre_a_buscar;
					//	int indice_empleado = buscar(empleado, cad, nombre_a_buscar,0);
					//	if (indice_empleado != -1) {
					//		cout << "Bibliotecario encontrado:" << endl;
					//		imprimir(empleado, cad, indice_empleado);
					//	} else {
					cout << "Bibliotecario no encontrado." << endl;
					//	}
				}
				break;
				case 4:
					return 0;
				default:
					cout << "Opción no válida. Intente de nuevo." << endl;
					break;
				}
			}
			break;
		case 4:
			return 0;
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
			break;
		}
	}
	return 0;
}
		 
int main() {
	 const int CAD = 5;
	 Libro vt[CAD];
	 Usuario usuario;
	 Empleado empleado;
	 const int longitudApellido = 6;
	 const int longitudNombre = 6;
	 srand(time(NULL));
	 string titulos[] = {"Aprenda C", "Calculo 1", "Problemas y Soluciones", "Tecnología Moderna", "Los Animales"};
	 string autores[] = {"Erich Segal", "William P. Blatty", "Richard Bach", "Erica Jong", "Gabriel Garciía Márquez"};
	 
	 
	 
	 // Llamada al menú
	 menu(vt, CAD, usuario, empleado, 6, 6, "", "", 0,titulos,autores);
	 
	 return 0;
 }
