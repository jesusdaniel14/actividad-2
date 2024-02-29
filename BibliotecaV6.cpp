#include <iostream>
#include <ctime>
#include <string>
#include <cctype> // Para toupper
#include <vector>
#include <map>
using namespace std;

// Estructura para datos de tiempo
struct S_Tiempo {
	int nDia;
	int nMes;
	int nAnio;
};

// Estructura para libros
struct S_Libro {
	int nSNBI;
	string sTituloLibro;
	string sAutorLibro;
	S_Tiempo tFechaPublicacion;
	string sEditorial;
	int nNumEstante;
	string arrEstado;
	
};

// Estructura para usuarios
struct S_Usuario {
	int nIDUsuario;
	string sNombre;
	string sApellido;
	string sContrasena;
	int nTelf;
};

// Estructura para empleados
struct S_Empleado {
	int nIDEmpleado;
	string sNombre;
	string sApellido;
	string sEmail;
	int nTelf;
};

// Función para llenar datos de libros
void llenar(int nCad, S_Libro vt[], string arrTitulos[], string arrAutores[],int nNumEstante, string arrEditorial[],string arrEstado[]) {
	for (int i = 0; i < nCad; i++) {
		vt[i].nSNBI = 1 + i;
		vt[i].sTituloLibro = arrTitulos[rand() % 5];
		vt[i].sAutorLibro = arrAutores[rand() % 5];
		vt[i].tFechaPublicacion.nDia = 1 + rand() % 31;
		vt[i].tFechaPublicacion.nMes = 1 + rand() % 12;
		vt[i].tFechaPublicacion.nAnio = 1980 + rand() % 41;
		vt[i].nNumEstante = 1 + rand() % 20;
		vt[i].sEditorial = arrEditorial[i];
		vt[i].arrEstado = arrEstado[rand() % 3];	}
}

// Función para imprimir detalles de libros
void imprimir(const S_Libro vt[], int nCad, int nIndex) {
	if (nIndex < nCad) {
		cout << "SNBI:  " << vt[nIndex].nSNBI << endl;
		cout << "Titulo: " << vt[nIndex].sTituloLibro << endl;
		cout << "Autor: " << vt[nIndex].sAutorLibro << endl;
		cout << "Fecha de publicacion: " << vt[nIndex].tFechaPublicacion.nDia << "/"
			<< vt[nIndex].tFechaPublicacion.nMes << "/"
			<< vt[nIndex].tFechaPublicacion.nAnio << endl;
		cout << "Numero de Estante: " << vt[nIndex].nNumEstante  << endl;
		cout << "Editorial: " << vt[nIndex].sEditorial << endl;
		cout << "Condicion del libro: "<< vt[nIndex].arrEstado <<endl;
		cout << endl;
		
		imprimir(vt, nCad, nIndex + 1); // Llamada recursiva para el siguiente libro
	}
}

// Función para llenar datos de usuarios
void llenar(int nCad, S_Usuario usuarios[], string arrNombres[], string arrApellidos[],int nTelf) {
	for (int i = 0; i < nCad; i++) {
		usuarios[i].nIDUsuario = 201 + i;
		usuarios[i].sNombre = arrNombres[rand() % 10];
		usuarios[i].sApellido = arrApellidos[rand() % 10];
		usuarios[i].sContrasena = usuarios[i].sNombre + usuarios[i].sApellido; // Concatenación de nombre y apellido
		usuarios[i].nTelf =70000000+rand()%79999999;
	}
}

// Función para imprimir detalles de usuarios
void imprimir(const S_Usuario usuarios[], int nCad, int nIndex,int nTelf) {
	if (nIndex < nCad) {
		cout << "ID Usuario:  " << usuarios[nIndex].nIDUsuario << endl;
		cout << "Nombre: " << usuarios[nIndex].sNombre << endl;
		cout << "Apellido: " << usuarios[nIndex].sApellido << endl;
		cout << "Contraseña: " << usuarios[nIndex].sContrasena << endl;
		cout << "Telefono: " << usuarios[nIndex].nTelf << endl;
		cout << endl;
		
		imprimir(usuarios, nCad, nIndex + 1,nTelf); // Llamada recursiva para el siguiente usuario
	}
}

// Función para llenar datos de empleados
void llenar(int nCad, S_Empleado empleados[], string arrNombres[], string arrApellidos[],int nTelf) {
	for (int i = 0; i < nCad; i++) {
		empleados[i].nIDEmpleado = 101 + i;
		empleados[i].sNombre = arrNombres[rand() % 10];
		empleados[i].sApellido = arrApellidos[rand() % 10];
		empleados[i].sEmail = empleados[i].sNombre + empleados[i].sApellido + "@gmail.com"; // Concatenación de nombre y apellido
		empleados[i].nTelf =70000000+rand()%79999999;
	}
}

// Función para imprimir detalles de empleados
void imprimir(const S_Empleado empleados[], int nCad, int nIndex,int nTelf) {
	if (nIndex < nCad) {
		cout << "ID Empleado:  " << empleados[nIndex].nIDEmpleado << endl;
		cout << "Nombre: " << empleados[nIndex].sNombre << endl;
		cout << "Apellido: " << empleados[nIndex].sApellido << endl;
		cout << "Email: " << empleados[nIndex].sEmail << endl;
		cout << "Telefono: " << empleados[nIndex].nTelf << endl;
		cout << endl;
		
		imprimir(empleados, nCad, nIndex + 1,nTelf); // Llamada recursiva para el siguiente empleado
	}
}

// Función para buscar libros por título (por letras) y contar coincidencias
int buscar(const S_Libro vt[], int nCad, const string& letras, int nIndex, int& nContador, vector<string>& titulosEncontrados) {
	if (nIndex >= nCad) {
		return nContador;
	}
	
	// Convertir las letras ingresadas y el título del libro a mayúsculas para comparar
	string letrasUpper = letras;
	for (char& c : letrasUpper) {
		c = toupper(c);
	}
	
	string tituloLibroUpper = vt[nIndex].sTituloLibro;
	for (char& c : tituloLibroUpper) {
		c = toupper(c);
	}
	
	if (tituloLibroUpper.find(letrasUpper) != string::npos) {
		nContador++;
		titulosEncontrados.push_back(vt[nIndex].sTituloLibro); // Guardar el título encontrado
	}
	
	return buscar(vt, nCad, letras, nIndex + 1, nContador, titulosEncontrados); // Llamada recursiva para el siguiente libro
}

// Función para buscar usuarios por nombre (por letras) y contar coincidencias
int buscar(const S_Usuario usuarios[], int nCad, const string& letras, int nIndex, int& nContador, vector<string>& nombresEncontrados) {
	if (nIndex >= nCad) {
		return nContador;
	}
	
	// Convertir las letras ingresadas y el nombre del usuario a mayúsculas para comparar
	string letrasUpper = letras;
	for (char& c : letrasUpper) {
		c = toupper(c);
	}
	
	string nombreUsuarioUpper = usuarios[nIndex].sNombre;
	for (char& c : nombreUsuarioUpper) {
		c = toupper(c);
	}
	
	if (nombreUsuarioUpper.find(letrasUpper) != string::npos) {
		nContador++;
		nombresEncontrados.push_back(usuarios[nIndex].sNombre); // Guardar el nombre encontrado
	}
	
	return buscar(usuarios, nCad, letras, nIndex + 1, nContador, nombresEncontrados); // Llamada recursiva para el siguiente usuario
}

// Función para buscar empleados por nombre (por letras) y contar coincidencias
int buscar(const S_Empleado empleados[], int nCad, const string& letras, int nIndex, int& nContador, vector<string>& nombresEncontrados) {
	if (nIndex >= nCad) {
		return nContador;
	}
	
	// Convertir las letras ingresadas y el nombre del empleado a mayúsculas para comparar
	string letrasUpper = letras;
	for (char& c : letrasUpper) {
		c = toupper(c);
	}
	
	string nombreEmpleadoUpper = empleados[nIndex].sNombre;
	for (char& c : nombreEmpleadoUpper) {
		c = toupper(c);
	}
	
	if (nombreEmpleadoUpper.find(letrasUpper) != string::npos) {
		nContador++;
		nombresEncontrados.push_back(empleados[nIndex].sNombre); // Guardar el nombre encontrado
	}
	
	return buscar(empleados, nCad, letras, nIndex + 1, nContador, nombresEncontrados); // Llamada recursiva para el siguiente empleado
}

// Función para mostrar cuántas veces se repite cada nombre
void mostrarConteo(const vector<string>& nombresEncontrados) {
	map<string, int> conteo;
	for (const string& nombre : nombresEncontrados) {
		conteo[nombre]++;
	}
	
	for (const auto& pair : conteo) {
		cout << "Nombre: " << pair.first << ", Repeticiones: " << pair.second << endl;
	}
}

int main() {
	int opcion;
	const int CAD = 5;
	S_Libro vt[CAD];
	S_Usuario usuarios[CAD];
	S_Empleado empleados[CAD];
	srand(time(NULL));
	int nTelf;
	int nNumEstante;
	
	string arrTitulos[] = { "Aprenda C", "Calculo 1", "Problemas y Soluciones", "Tecnología Moderna", "Los Animales" };
	string arrAutores[] = { "Erich Segal", "William P. Blatty", "Richard Bach", "Erica Jong", "Gabriel Garciía Márquez" };
	string arrNombres[] = { "Juan", "Pedro", "Roberto", "Silvia", "Karen", "Rafaela", "Sofia", "Alicia", "Jaime", "Iver" };
	string arrApellidos[] = { "Peralta", "Lazarte", "Cuba", "Torre", "Saucedo", "Ruiz", "Flores", "Herrera", "Fernandez", "Aguilera" };
	string arrEditorial[] = { "Comunity", "Santa Cruz", "La Hogera" , "Editorial C", "AyR" };
	string arrEstado[] = { "Bueno", "Aceptable", "Malo"};
	
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
			llenar(CAD, vt, arrTitulos, arrAutores, nNumEstante, arrEditorial,arrEstado);
			llenar(CAD, usuarios, arrNombres, arrApellidos, nTelf);
			llenar(CAD, empleados, arrNombres, arrApellidos, nTelf);
			cout << "Datos llenados" << endl;
			break;
		case 2:
			while (true) {
				cout << "\nSUBMENU LISTADO" << endl;
				cout << "1. Listado de libros" << endl;
				cout << "2. Listado de usuarios" << endl;
				cout << "3. Listado de empleados" << endl;
				cout << "4. Salir" << endl;
				
				int nSubOpcion;
				cout << "Seleccione una opción: ";
				cin >> nSubOpcion;
				switch (nSubOpcion) {
				case 1:
					imprimir(vt, CAD, 0);
					break;
				case 2:
					imprimir(usuarios, CAD, 0,nTelf);
					break;
				case 3:
					imprimir(empleados, CAD, 0,nTelf);
					break;
				case 4:
					break; // Regresar al Menú Principal
				default:
					cout << "Opción no válida. Intente de nuevo." << endl;
				}
				if (nSubOpcion == 4) {
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
				
				int nSubOpcion;
				cout << "Seleccione una opción: ";
				cin >> nSubOpcion;
				switch (nSubOpcion) {
				case 1:
				{
					string letras_a_buscar;
					cout << "Ingrese las letras para buscar en el título del libro: ";
					cin.ignore(); // Ignorar el buffer del enter anterior
					getline(cin, letras_a_buscar);
					for (char& c : letras_a_buscar) {
						c = toupper(c); // Convertir a mayúsculas
					}
					int nContadorLibros = 0;
					vector<string> titulosEncontrados;
					cout << "Número de coincidencias encontradas: " << buscar(vt, CAD, letras_a_buscar, 0, nContadorLibros, titulosEncontrados) << endl;
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
					int nContadorUsuarios = 0;
					vector<string> nombresEncontrados;
					cout << "Número de coincidencias encontradas: " << buscar(usuarios, CAD, letras_a_buscar, 0, nContadorUsuarios, nombresEncontrados) << endl;
					cout << "Nombres de usuarios encontrados:" << endl;
					for (const string& nombre : nombresEncontrados) {
						cout << "- " << nombre << endl;
					}
					mostrarConteo(nombresEncontrados); // Mostrar el conteo de nombres
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
					int nContadorEmpleados = 0;
					vector<string> nombresEncontrados;
					cout << "Número de coincidencias encontradas: " << buscar(empleados, CAD, letras_a_buscar, 0, nContadorEmpleados, nombresEncontrados) << endl;
					cout << "Nombres de empleados encontrados:" << endl;
					for (const string& nombre : nombresEncontrados) {
						cout << "- " << nombre << endl;
					}
					mostrarConteo(nombresEncontrados); // Mostrar el conteo de nombres
				}
				break;
				case 4:
					break;
				default:
					cout << "Opción no válida. Intente de nuevo." << endl;
				}
				if (nSubOpcion == 4) {
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
