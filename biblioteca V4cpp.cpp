#include <iostream>
#include <ctime>
#include <string>
#include <cctype> // Para toupper
#include <vector>
using namespace std;

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

// Estructura para usuarios
struct Usuario {
	int idUsuario;
	string nombre;
	string apellido;
	string contrasena;
};

// Estructura para empleados
struct Empleado {
	int idEmpleado;
	string nombre;
	string apellido;
	string email;
};

// Función para llenar datos de libros
void llenar(int cad, Libro vt[], string titulos[], string autores[]) {
	for (int i = 0; i < cad; i++) {
		vt[i].snbi = 1 + i;
		vt[i].tituloLibro = titulos[rand() % 5];
		vt[i].autorLibro = autores[rand() % 5];
		vt[i].fechaPublicacion.dia = 1 + rand() % 31;
		vt[i].fechaPublicacion.mes = 1 + rand() % 12;
		vt[i].fechaPublicacion.anio = 1980 + rand() % 41;
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

// Función para llenar datos de usuarios
void llenar(int cad, Usuario usuarios[], string nombres[], string apellidos[]) {
	for (int i = 0; i < cad; i++) {
		usuarios[i].idUsuario = 201 + i;
		usuarios[i].nombre = nombres[rand() % 10];
		usuarios[i].apellido = apellidos[rand() % 10];
		usuarios[i].contrasena = usuarios[i].nombre + usuarios[i].apellido; // Concatenación de nombre y apellido
	}
}

// Función para imprimir detalles de usuarios
void imprimir(const Usuario usuarios[], int cad, int index) {
	if (index < cad) {
		cout << "ID Usuario:  " << usuarios[index].idUsuario << endl;
		cout << "Nombre: " << usuarios[index].nombre << endl;
		cout << "Apellido: " << usuarios[index].apellido << endl;
		cout << "Contraseña: " << usuarios[index].contrasena << endl;
		cout << endl;
		
		imprimir(usuarios, cad, index + 1); // Llamada recursiva para el siguiente usuario
	}
}

// Función para llenar datos de empleados
void llenar(int cad, Empleado empleados[], string nombres[], string apellidos[]) {
	for (int i = 0; i < cad; i++) {
		empleados[i].idEmpleado = 101 + i;
		empleados[i].nombre = nombres[rand() % cad];
		empleados[i].apellido = apellidos[rand() % cad];
		empleados[i].email = empleados[i].nombre + empleados[i].apellido + "@gmail.com"; // Concatenación de nombre y apellido
	}
}

// Función para imprimir detalles de empleados
void imprimir(const Empleado empleados[], int cad, int index) {
	if (index < cad) {
		cout << "ID Empleado:  " << empleados[index].idEmpleado << endl;
		cout << "Nombre: " << empleados[index].nombre << endl;
		cout << "Apellido: " << empleados[index].apellido << endl;
		cout << "Email: " << empleados[index].email << endl;
		cout << endl;
		
		imprimir(empleados, cad, index + 1); // Llamada recursiva para el siguiente empleado
	}
}

// Función para buscar libros por título (por letras) y contar coincidencias
int buscar(const Libro vt[], int cad, const string& letras, int index, int& contador, vector<string>& titulosEncontrados) {
	if (index >= cad) {
		return contador;
	}
	
	// Convertir las letras ingresadas y el título del libro a mayúsculas para comparar
	string letrasUpper = letras;
	for (char& c : letrasUpper) {
		c = toupper(c);
	}
	
	string tituloLibroUpper = vt[index].tituloLibro;
	for (char& c : tituloLibroUpper) {
		c = toupper(c);
	}
	
	if (tituloLibroUpper.find(letrasUpper) != string::npos) {
		contador++;
		titulosEncontrados.push_back(vt[index].tituloLibro); // Guardar el título encontrado
	}
	
	return buscar(vt, cad, letras, index + 1, contador, titulosEncontrados); // Llamada recursiva para el siguiente libro
}

// Función para buscar usuarios por nombre (por letras) y contar coincidencias
int buscar(const Usuario usuarios[], int cad, const string& letras, int index, int& contador, vector<string>& nombresEncontrados) {
	if (index >= cad) {
		return contador;
	}
	
	// Convertir las letras ingresadas y el nombre del usuario a mayúsculas para comparar
	string letrasUpper = letras;
	for (char& c : letrasUpper) {
		c = toupper(c);
	}
	
	string nombreUsuarioUpper = usuarios[index].nombre;
	for (char& c : nombreUsuarioUpper) {
		c = toupper(c);
	}
	
	if (nombreUsuarioUpper.find(letrasUpper) != string::npos) {
		contador++;
		nombresEncontrados.push_back(usuarios[index].nombre); // Guardar el nombre encontrado
	}
	
	return buscar(usuarios, cad, letras, index + 1, contador, nombresEncontrados); // Llamada recursiva para el siguiente usuario
}

// Función para buscar empleados por nombre (por letras) y contar coincidencias
int buscar(const Empleado empleados[], int cad, const string& letras, int index, int& contador, vector<string>& nombresEncontrados) {
	if (index >= cad) {
		return contador;
	}
	
	// Convertir las letras ingresadas y el nombre del empleado a mayúsculas para comparar
	string letrasUpper = letras;
	for (char& c : letrasUpper) {
		c = toupper(c);
	}
	
	string nombreEmpleadoUpper = empleados[index].nombre;
	for (char& c : nombreEmpleadoUpper) {
		c = toupper(c);
	}
	
	if (nombreEmpleadoUpper.find(letrasUpper) != string::npos) {
		contador++;
		nombresEncontrados.push_back(empleados[index].nombre); // Guardar el nombre encontrado
	}
	
	return buscar(empleados, cad, letras, index + 1, contador, nombresEncontrados); // Llamada recursiva para el siguiente empleado
}

int main() {
	int opcion;
	const int CAD = 5;
	Libro vt[CAD];
	Usuario usuarios[CAD];
	Empleado empleados[CAD];
	srand(time(NULL));
	
	string titulos[] = { "Aprenda C", "Calculo 1", "Problemas y Soluciones", "Tecnología Moderna", "Los Animales" };
	string autores[] = { "Erich Segal", "William P. Blatty", "Richard Bach", "Erica Jong", "Gabriel Garciía Márquez" };
	string nombres[] = { "Juan", "Pedro", "Roberto", "Silvia", "Karen", "Rafaela", "Sofia", "Alicia", "Jaime", "Iver" };
	string apellidos[] = { "Peralta", "Lazarte", "Cuba", "Torre", "Saucedo", "Ruiz", "Flores", "Herrera", "Fernandez", "Aguilera" };
	
	do {
		cout << "\nMENU" << endl;
		cout << "1. Llenar datos" << endl;
		cout << "2. Listado" << endl;
		cout << "3. Busqueda" << endl;
		cout << "4. Salir" << endl;
		cout << "" << endl;
		
		cout << "Seleccione una opción: ";
		cin >> opcion;
		cout << "--------------------" << endl;
		switch (opcion) {
		case 1:
			llenar(CAD, vt, titulos, autores);
			llenar(CAD, usuarios, nombres, apellidos);
			llenar(CAD, empleados, nombres, apellidos);
			cout << "Datos llenados" << endl;
			break;
		case 2:
			while (true) {
				cout << "\nSUBMENU LISTADO" << endl;
				cout << "1. Listado de libros" << endl;
				cout << "2. Listado de usuarios" << endl;
				cout << "3. Listado de empleados" << endl;
				cout << "4. Salir" << endl;
				
				int opcion;
				cout << "Seleccione una opción: ";
				cin >> opcion;
				switch (opcion) {
				case 1:
					imprimir(vt, CAD, 0);
					break;
				case 2:
					imprimir(usuarios, CAD, 0);
					break;
				case 3:
					imprimir(empleados, CAD, 0);
					break;
				case 4:
					break; // Regresar al Menú Principal
				default:
					cout << "Opción no válida. Intente de nuevo." << endl;
				}
				if (opcion == 4) {
					break; // Salir del submenú
				}
			}
			break;
		case 3:
			while (true) {
				cout << "\nSUBMENU BUSQUEDA" << endl;
				cout << "1. Buscar libro" << endl;
				cout << "2. Buscar usuario" << endl;
				cout << "3. Buscar empleado" << endl;
				cout << "4. Salir" << endl;
				
				int opcion;
				cout << "Seleccione una opción: ";
				cin >> opcion;
				switch (opcion) {
				case 1:
				{
					string letras_a_buscar;
					cout << "Ingrese las letras para buscar en el título del libro: ";
					cin.ignore(); // Ignorar el buffer del enter anterior
					getline(cin, letras_a_buscar);
					for (char& c : letras_a_buscar) {
						c = toupper(c); // Convertir a mayúsculas
					}
					int contadorLibros = 0;
					vector<string> titulosEncontrados;
					cout << "Número de coincidencias encontradas: " << buscar(vt, CAD, letras_a_buscar, 0, contadorLibros, titulosEncontrados) << endl;
					cout << "Títulos encontrados:" << endl;
					for (const string& titulo : titulosEncontrados) {
						cout << "- " << titulo << endl;
					}
				}
				break;
				case 2:
				{
					string letras_a_buscar;
					cout << "Ingrese las letras para buscar en el nombre del usuario: ";
					cin.ignore(); // Ignorar el buffer del enter anterior
					getline(cin, letras_a_buscar);
					for (char& c : letras_a_buscar) {
						c = toupper(c); // Convertir a mayúsculas
					}
					int contadorUsuarios = 0;
					vector<string> nombresEncontrados;
					cout << "Número de coincidencias encontradas: " << buscar(usuarios, CAD, letras_a_buscar, 0, contadorUsuarios, nombresEncontrados) << endl;
					cout << "Nombres de usuarios encontrados:" << endl;
					for (const string& nombre : nombresEncontrados) {
						cout << "- " << nombre << endl;
					}
				}
				break;
				case 3:
				{
					string letras_a_buscar;
					cout << "Ingrese las letras para buscar en el nombre del empleado: ";
					cin.ignore(); // Ignorar el buffer del enter anterior
					getline(cin, letras_a_buscar);
					for (char& c : letras_a_buscar) {
						c = toupper(c); // Convertir a mayúsculas
					}
					int contadorEmpleados = 0;
					vector<string> nombresEncontrados;
					cout << "Número de coincidencias encontradas: " << buscar(empleados, CAD, letras_a_buscar, 0, contadorEmpleados, nombresEncontrados) << endl;
					cout << "Nombres de empleados encontrados:" << endl;
					for (const string& nombre : nombresEncontrados) {
						cout << "- " << nombre << endl;
					}
				}
				break;
				case 4:
					break;
				default:
					cout << "Opción no válida. Intente de nuevo." << endl;
				}
				if (opcion == 4) {
					break; // Salir del submenú
				}
			}
			break;
		case 4:
			return 0;
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
			break;
		}
	} while (opcion != 0);
	
	return 0;
}
