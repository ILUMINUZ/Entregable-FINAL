#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const size_t TAMANO = 5;

// Definicion de Libro
class Libro {
private:
	
	int lISBN;
	string lTITULO;
	string lAUTOR;
	int lPUBLICACION;
	string lGENERO;
	double lPRECIO;
	int lCantidadDisponible;
	
public:
	//Constructor por defecto
	
	Libro() {
		this->lISBN = 0;
		this->lTITULO = "";
		this->lAUTOR = "";
		this->lPUBLICACION = 0;
		this->lGENERO = "";
		this->lPRECIO = 0.0;
		this->lCantidadDisponible = 0;
	}
	
	// Constructor por atributos
	
	Libro(int isbn, string titulo, string autor, int publicacion, string genero, double precio, int disponibles) {
		this->lISBN = isbn;
		this->lTITULO = titulo;
		this->lAUTOR = autor;
		this->lPUBLICACION = publicacion;
		this->lGENERO = genero;
		this->lPRECIO = precio;
		this->lCantidadDisponible = disponibles;
		
	}
	
	// Metodos de obtencion de los atributos
	
	int get_ISBN() const { return lISBN; }
	string get_Titulo() const { return lTITULO; }
	string get_Autor() const { return lAUTOR; }
	int get_Publicacion() const { return lPUBLICACION; }
	string get_Genero() const { return lGENERO; }
	double get_Precio() const { return lPRECIO; }
	int get_disponibles() const { return lCantidadDisponible; }
	
	// Metodos de modificacion de los atributos
	
	void set_ISBN(int isbn) { lISBN = isbn; }
	void set_Titulo(const string& titulo) { lTITULO = titulo; }
	void set_Autor(const string& autor) { lAUTOR = autor; }
	void set_Publicacion(int publicacion) { lPUBLICACION = publicacion; }
	void set_Genero(const string& genero) { lGENERO = genero; }
	void set_Precio(double precio) { lPRECIO = precio; }
	void set_disponibles(int disponibles) { lCantidadDisponible = disponibles; }
};

// Definicion de la clase Persona

class Persona {
private:
	
	int pID;
	string pNOMBRE;
	string pAPELLIDO;
	string pEMAIL;
	
public:
	
	// Constructor por defecto
	
	Persona() {
		this->pID = 0;
		this->pNOMBRE = "sin nombre";
		this->pAPELLIDO = "sin apellido";
		this->pEMAIL = "sin email";
	}
	
	// Constructor por parametros
	
	Persona(int id, string nombre, string apellido, string email) {
		this->pID = id;
		this->pNOMBRE = nombre;
		this->pAPELLIDO = apellido;
		this->pEMAIL = email;
	}
	
	// Metodos de obtencion de los atributos
	
	int get_ID() const { return pID; }
	string get_Nombre() const { return pNOMBRE; }
	string get_Apellido() const { return pAPELLIDO; }
	string get_Email() const { return pEMAIL; }
	
	// Metodos de modificacion de los atributos
	
	void set_ID(int id) { pID = id;}
	void set_Nombre(const string& nombre) { pNOMBRE = nombre; }
	void set_Apellido(const string& apellido) { pAPELLIDO = apellido; }
	void set_Email(const string& email) { pEMAIL = email; }
};

// Definicion de la clase Usuario

class Usuario : public Persona {
private:
	int uCarnet;
	
public:
	
	// Constructor por defecto
	
	Usuario() {
		this->uCarnet = 0;
	}
	
	//Constructor por parametros
	
	Usuario(int id, string nombre, string apellido, string email, int Carnet): Persona(id, nombre, apellido, email){
		this->uCarnet=Carnet;
	}
	
	// Metodos de obtencion de los atributos
	
	int get_Carnet() const { return uCarnet; }
	
	// Metodos de modificacion de los atributos
	
	void set_Carnet(int Carnet) { uCarnet = Carnet; }
};

// Definicion de la clase Bibliotecario

class Bibliotecario : public Persona {
private:
	double bSALARIO;
public:
	// Constructor por defecto
	Bibliotecario() {
		this->bSALARIO = 0.0;
	}
	//constructor por parametros
	Bibliotecario(int id, string nombre, string apellido, string email, double salario): Persona(id, nombre, apellido, email){
		this->bSALARIO=salario;
	}
	// Metodos de obtencion de los atributos
	double get_Salario() const { return bSALARIO; }
	// Metodos de modificacion de los atributos
	void set_Salario(double salario) { bSALARIO = salario; }
};
// Definici�n clase GestorLibros
class GestorLibros {
private:
	
	Libro libros[TAMANO];
	int tamanoActual;
	
public:
	
	GestorLibros() : tamanoActual(0) {}
	bool tituloRepetido(const string& titulo, int cantidad) const {
		for (int i = 0; i < cantidad; i++) {
			if (titulo == libros[i].get_Titulo()) {
				return true; // En caso de titulo repetido
			}
		}
		return false; // En caso de titulo no repetido
	}
	
	void llenar() {
		string listaTitulo[] = {"El Secreto del Universo", "El Viaje Perdido", "El Misterio del Tiempo", "Aventuras en la Selva", "El Poder de la Magia", "C�digo Oculto", "Explorando el Cosmos", "El Tesoro Perdido", "Viaje al Pasado", "Pesadilla en la Oscuridad"};
		string listaAutor[] = {"Isabel Allende", "Haruki Murakami", "Agatha Christie", "Jules Verne", "Roald Dahl", "J.R.R. Tolkien", "Jane Austen", "Stephen King", "Dan Brown", "Edgar Allan Poe"};
		string listaGenero[] = {"Ciencia Ficci�n", "Aventura", "Misterio", "Infantil", "Fantas�a", "�pica", "Romance", "Terror", "Thriller", "Suspenso"};
		
		srand(time(nullptr)); // Inicializar la semilla del generador de n�meros aleatorios
		tamanoActual = 0; // Reiniciar el contador para llenar desde el principio
		for (int i = 0; i < TAMANO; i++) {
			string tituloAleatorio;
			do {
				int indiceTitulo = rand() % 10; //generacion de numero randomico de 0 a 9
				tituloAleatorio = listaTitulo[indiceTitulo];
			} while (tituloRepetido(tituloAleatorio, tamanoActual)); // Verificador de titulos repetidos
			int isbnAleatorio = i + 1;
			int indiceAutor = rand() % 10;
			int indiceGenero = rand() % 10;
			int publicacionAleatoria = rand() % 25 + 1980; // Anio entre 1980 y actualidad
			double precioAleatorio = rand() % 300 + 100; // Precios entre 50 y 399
			int disponiblesAleatorias = rand() % 50 + 10; // disponibles entre 10 y 59
			string AutorAleatorio = listaAutor[indiceAutor];
			string GeneroAleatorio = listaGenero[indiceGenero];
			libros[i] = Libro(isbnAleatorio, tituloAleatorio,AutorAleatorio , publicacionAleatoria,GeneroAleatorio , precioAleatorio, disponiblesAleatorias);
			tamanoActual++;
		}
	}
	
	void mostrar() const {
		if (tamanoActual == 0) { // Verifica si no hay libros llenados
			cout << "Datos no llenados." << endl;
			return;
		}
		//imprimir datos de los libros
		cout << setw(2) << right << "ISBN" << setw(10) << "Titulo" << setw(24) << "Autor" << setw(24) << "Anio" << setw(13) << "Genero" << setw(15) << "Precio" << setw(10) << "disponibles" << endl;
		for (int i = 0; i < tamanoActual; i++) {
			cout << left << setw(8) << libros[i].get_ISBN() << setw(25) << libros[i].get_Titulo() << setw(25) << libros[i].get_Autor() << setw(11) << libros[i].get_Publicacion() << setw(15) << libros[i].get_Genero() << setw(10) << libros[i].get_Precio() << setw(10) << libros[i].get_disponibles() << endl;
		}
	}
	
	// Funci�n para mostrar los datos de los libros en forma de bloque
	
	void mostrar(string bloque) const {
		if (tamanoActual == 0) { // Verificando si no hay libros llenos
			cout << "Datos no llenados." << endl; 
			return;
		}
		cout << "Datos de libros en bloques: " << endl;
		for (int i = 0; i < tamanoActual; i++) {
			
			cout << "ISBN: " << libros[i].get_ISBN() << endl;
			cout << "Titulo: " << libros[i].get_Titulo() << endl; 
			cout << "Autor: " << libros[i].get_Autor() << endl;
			cout << "Anio: " << libros[i].get_Publicacion() << endl; 
			cout << "Genero: " << libros[i].get_Genero() << endl; 
			cout << "Precio: " << libros[i].get_Precio() << endl;
			cout << "disponibles: " << libros[i].get_disponibles() << endl << endl;
		}
		cout << bloque << endl;
	}
	
	// Funcion para tranformar en minuculas las cadenas
	
	string convertir(const string& cadena) const {
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	
	// Funcion recursiva para buscar libros por titulo
	
	void buscar(int indice, int fin, const string& busqueda) const {
		if (indice < fin) { //condicion base
			// Transformar a min�sculas los atributos del los libro y la cadena de b�squeda
			string tituloMinuscula = convertir(libros[indice].get_Titulo());
			string autorMinuscula = convertir(libros[indice].get_Autor());
			string generoMinuscula = convertir(libros[indice].get_Genero());
			string precioStr = to_string(libros[indice].get_Precio());
			string busquedaMinuscula = convertir(busqueda);
			if (indice == 0) { //mostrar el encabezado de la tabla
				cout << setw(2) << right << "ISBN" << setw(10) << "Titulo" << setw(24) << "Autor" << setw(24) << "Anio" << setw(13) << "Genero" << setw(15) << "Precio" << setw(10)<<"Disponibles" << endl;
			}
			// Verificar si la busqueda coincide con el titulo, autor, genero o precio
			if (tituloMinuscula.find(busquedaMinuscula) != string::npos || autorMinuscula.find(busquedaMinuscula) != string::npos || generoMinuscula.find(busquedaMinuscula) != string::npos || precioStr.find(busquedaMinuscula) != string::npos) {
				//imprime los datos de los libros que coincidan con la busqueda
				cout << left << setw(8) << libros[indice].get_ISBN() << setw(25) << libros[indice].get_Titulo() << setw(25) << libros[indice].get_Autor() << setw(11) << libros[indice].get_Publicacion() << setw(15) << libros[indice].get_Genero() << setw(10) << libros[indice].get_Precio() << setw(10) << libros[indice].get_disponibles() << endl;
			}
			buscar(indice + 1, fin, busqueda); // Llamada recursiva con el siguiente libro
		}
	}
};

// Definicion de la clase GestorUsuarios

class GestorUsuarios {
private:
	Usuario usuarios[TAMANO];
	int tamanoActual;
public:
	GestorUsuarios() : tamanoActual(0) {}
	void llenar() { // Funcion para llenar el arreglo de usuarios con datos aleatorios
		string listaNombres[] = {"Juan", "Maria", "Luis", "Ana", "Carlos", "Laura", "Pedro", "Elena", "Javier", "Sofia"};
		string listaApellidos[] = {"Peralta", "Osinaga", "Rodriguez", "Escobar", "Lopez", "Gonzalez", "Mendoza", "Roca", "Garcia", "Torres"};
		srand(time(nullptr)); // Inicializar la semilla del generador de n�meros aleatorios
		tamanoActual = 0; // Reiniciar el contador para llenar desde el principio
		for (int i = 0; i < TAMANO; ++i) {
			int NombreIndice = rand() % 10; //generacion de numero randomico de 0 al 9
			int ApellidoIndice = rand() % 10; //generacion de numero randomico de 0 al 9
			int idrandom = i + 1;
			int CarnetRandom = (rand() % 2 + 6) * 10000000 + rand() % 10000000;
			//asignar nombre y apellido de los arrays de acuerdo al indice generado randomicamente
			string NombreRandom = listaNombres[NombreIndice];
			string ApellidoRandom = listaApellidos[ApellidoIndice];
			string emailRandom = NombreRandom + ApellidoRandom + "@gmail.com";
			usuarios[i] = Usuario(idrandom, NombreRandom, ApellidoRandom, emailRandom, CarnetRandom);
			tamanoActual++; // Incrementar el contador de usuarios
		}
	}
	void mostrar() const {  // Funcion para mostrar los datos de los usuarios en forma de tabla
		if (tamanoActual == 0) { // Verificar si no hay usuarios para mostrar
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		cout << setw(5) << right << "Usuario" << setw(14) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Carnet" << endl;
		for (int i = 0; i < tamanoActual; ++i) { //imprimir datos de los usuarios
			cout << left << setw(15) << usuarios[i].get_ID() << setw(15) << usuarios[i].get_Nombre() << setw(15) << usuarios[i].get_Apellido() << setw(30) << usuarios[i].get_Email() << setw(15) << usuarios[i].get_Carnet() << endl;
		}
	}
	// Funci�n para mostrar los datos de los usuarios en forma de bloques
	void mostrar(string bloque) const {
		if (tamanoActual == 0) { // Verificar si no hay usuarios para mostrar
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		cout << "Datos de Usuarios en Bloques:" << endl;
		for (int i = 0; i < tamanoActual; ++i) { //imprimir datos de los usuarios
			//cout << "Usuario " << i+1 << ":" << endl;
			cout << "User ID: " << usuarios[i].get_ID() << endl;
			cout << "Nombre: " << usuarios[i].get_Nombre() << endl;
			cout << "Apellido: " << usuarios[i].get_Apellido() << endl;
			cout << "Email: " << usuarios[i].get_Email() << endl;
			cout << "Carnet: " << usuarios[i].get_Carnet() << endl << endl;
		}
	}
	// Funcion para convertir una cadena a minusculas
	string convertir(const string& cadena) const { 
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	// Funcion recursiva para buscar usuarios por nombre, apellido o nombre completo
	void buscar(int inicio, int fin, const string& busqueda) const {
		if (inicio < fin) {  //condicion base
			// Convertir a minusculas los atributos del usuario y la cadena de busqueda
			string nombreMinuscula = convertir(usuarios[inicio].get_Nombre()); //convertir las cadenas a minusculas
			string apellidoMinuscula = convertir(usuarios[inicio].get_Apellido());
			string emailMinuscula = convertir(usuarios[inicio].get_Email());
			string CarnetStr = to_string(usuarios[inicio].get_Carnet());
			string busquedaMinuscula = convertir(busqueda);
			if (inicio == 0) { //mostrar el encabezado de la tabla
				cout << setw(5) << right << "User ID" << setw(14) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Carnet" << endl;
			}
			// Verifica si la busqueda coincide con el nombre, apellido o nombre completo
			if (nombreMinuscula.find(busquedaMinuscula) != string::npos || apellidoMinuscula.find(busquedaMinuscula) != string::npos || (nombreMinuscula + " " + apellidoMinuscula).find(busquedaMinuscula) != string::npos || emailMinuscula.find(busquedaMinuscula) != string::npos || CarnetStr.find(busquedaMinuscula) != string::npos){
				// Imprimir los datos del usuario que coincidan con la busqueda
				cout << left << setw(15) << usuarios[inicio].get_ID() << setw(15) << usuarios[inicio].get_Nombre() << setw(15) << usuarios[inicio].get_Apellido() << setw(30) << usuarios[inicio].get_Email() << setw(15) << usuarios[inicio].get_Carnet() << endl;
			}
			buscar(inicio + 1, fin, busqueda); //llamada recursiva con el siguiente usuario
		}
	}
};
// Definicion de la clase GestorBibliotecarios
class GestorBibliotecarios {
private:
	Bibliotecario bibliotecarios[TAMANO];
	int tamanoActual;
public:
	GestorBibliotecarios() : tamanoActual(0) {}
	void llenar() { // Funci�n para llenar el arreglo de bibliotecarios con datos aleatorios
		string listaNombres[] = {"Elena", "Juan", "Lucia", "Raul", "Ana", "Diego", "Camila", "Javier", "Laura", "Daniel"};
		string listaApellidos[] = {"Gomez", "Perez", "Martinez", "Lopez", "Rodriguez", "Gutierrez", "Hernandez", "Diaz", "Fernandez", "Molina"};
		srand(time(nullptr)); // Inicializar la semilla del generador de n�meros aleatorios
		tamanoActual = 0; // Reiniciar el contador para llenar desde el principio
		for (int i = 0; i < TAMANO; ++i) {
			int NombreIndice = rand() % 10; //generar numero randomico del 0 al 9
			int ApellidoIndice = rand() % 10;
			int idrandom = i + 1;
			double salarioAleatorio = rand() % 1501 + 3000; // salario entre 1500 y 3000
			bibliotecarios[i] = Bibliotecario(idrandom, listaNombres[NombreIndice], listaApellidos[ApellidoIndice], listaNombres[NombreIndice] + listaApellidos[ApellidoIndice] + "@gmail.com", salarioAleatorio);
			tamanoActual++;
		}
	}
	void mostrar() const {  // Funcion para mostrar los datos de los bibliotecarios en forma de tabla
		if (tamanoActual == 0) { // Verificar si no hay bibliotecarios para mostrar
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		//imprimir datos de los bibliotecarios
		cout << setw(5) << right << "Empleado id" << setw(10) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Salario" << endl;
		for (int i = 0; i < tamanoActual; ++i) {
			cout << left << setw(15) << bibliotecarios[i].get_ID() << setw(15) << bibliotecarios[i].get_Nombre() << setw(15) << bibliotecarios[i].get_Apellido() << setw(30) << bibliotecarios[i].get_Email() << bibliotecarios[i].get_Salario() << "Bs" << endl;
		}
	}
	// Funci�n para mostrar los datos de los bibliotecarios en forma de bloques
	void mostrar(string bloque) const {
		if (tamanoActual == 0) {  // Verificar si no hay bibliotecarios para mostrar
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		cout << "Datos de Bibliotecarios en Bloques:" << endl;
		for (int i = 0; i < tamanoActual; ++i) { //imprimir datos de los bibliotecarios
			//cout << "Bibliotecario " << i+1 << ":" << endl;
			cout << "Empleado ID: " << bibliotecarios[i].get_ID() << endl;
			cout << "Nombre: " << bibliotecarios[i].get_Nombre() << endl;
			cout << "Apellido: " << bibliotecarios[i].get_Apellido() << endl;
			cout << "Email: " << bibliotecarios[i].get_Email() << endl;
			cout << "Salario: " << bibliotecarios[i].get_Salario() << " Bs" << endl << endl;
		}
	}
	string convertir(const string& cadena) const { // Funcion para convertir una cadena a minusculas
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	// Funcion recursiva para buscar bibliotecarios por nombre, apellido o nombre completo
	void buscar(int inicio, int fin, const string& busqueda) const {
		if (inicio < fin) { //condicion base
			// Convertir a minusculas los atributos del bibliotecario y la cadena de busqueda
			string nombreMinuscula = convertir(bibliotecarios[inicio].get_Nombre());
			string apellidoMinuscula = convertir(bibliotecarios[inicio].get_Apellido());
			string emailMinuscula = convertir(bibliotecarios[inicio].get_Email());
			string salarioStr= to_string(bibliotecarios[inicio].get_Salario());
			string busquedaMinuscula = convertir(busqueda);
			if (inicio == 0) { //mostrar el encabezado de la tabla
				cout << setw(5) << right << "Empleado ID" << setw(10) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Salario" << endl;
			}
			// Verifica si la busqueda coincide con el nombre, apellido o nombre completo
			if (nombreMinuscula.find(busquedaMinuscula) != string::npos || apellidoMinuscula.find(busquedaMinuscula) != string::npos || (nombreMinuscula + " " + apellidoMinuscula).find(busquedaMinuscula) != string::npos || emailMinuscula.find(busquedaMinuscula) != string::npos || salarioStr.find(busquedaMinuscula) != string::npos) {
				// Imprimir los datos del bibliotecario que coincidan con la busqueda
				cout << left << setw(15) << bibliotecarios[inicio].get_ID() << setw(15) << bibliotecarios[inicio].get_Nombre() << setw(15) << bibliotecarios[inicio].get_Apellido() << setw(30) << bibliotecarios[inicio].get_Email() << bibliotecarios[inicio].get_Salario() << "Bs" << endl;
			}
			buscar(inicio + 1, fin, busqueda); //llamada recursiva con el siguiente bibliotecario
		}
	}
};
// Menu para mostrar los listados
void menuListados(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
	int opcionListados;
	do {
		cout << "\nSubmenu de Listados:" << endl;
		cout << "1. Listado Libros" << endl;
		cout << "2. Listado Usuarios" << endl;
		cout << "3. Listado Bibliotecarios" << endl;
		cout << "0. Volver al Menu Principal" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcionListados;
		switch (opcionListados) {
		case 1:
		{
			char respuesta;
			cout << "Desea ver los datos en forma de tabla? (s/n): ";
			cin >> respuesta;
			if (respuesta == 's' || respuesta == 'S'){
				gestorL.mostrar();
			} else {
				gestorL.mostrar("bloque");
			}
		}  
		break;
		case 2:
		{
			char respuesta;
			cout << "Desea ver los datos en forma de tabla? (s/n): ";
			cin >> respuesta;
			if (respuesta == 's' || respuesta == 'S') {
				gestorU.mostrar();
			} else {
				gestorU.mostrar("Bloque");
			}
		}
		break;
		case 3:
		{
			char respuesta;
			cout << "Desea ver los datos en forma de tabla? (s/n): ";
			cin >> respuesta;
			if (respuesta == 's' || respuesta == 'S') {
				gestorB.mostrar();
			} else {
				gestorB.mostrar("Bloque");
			}
		}
		break;
		case 0:
			cout << "Volviendo al Menu Principal..." << endl;
			break;
		default:
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcionListados != 0);
}
// Menu para realizar busquedas
void menuBusqueda(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
	int opcionBusqueda;
	do {
		cout << "\nSubmenu de Busqueda:" << endl;
		cout << "1. Busqueda Libro" << endl;
		cout << "2. Busqueda Usuario" << endl;
		cout << "3. Busqueda Bibliotecario" << endl;
		cout << "0. Volver al Menu Principal" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcionBusqueda;
		switch (opcionBusqueda) {
		case 1:
		{
			string sBusquedaL;
			cout << "Ingrese el titulo del libro: ";
			cin.ignore(); // Limpiar el buffer de entrada
			getline(cin, sBusquedaL); // Leer la cadena de b�squeda
			cout << "\nResultados de la busqueda:" << endl;
			gestorL.buscar(0, TAMANO, sBusquedaL); // Realizar la busqueda de libros
		}
		break;
		case 2:
		{
			string sBusquedaU;
			cout << "Ingrese el nombre  o apellido: ";
			cin.ignore(); // Limpiar el buffer de entrada
			getline(cin, sBusquedaU); // Leer la cadena de b�squeda
			cout << "\nResultados de la busqueda:" << endl;
			gestorU.buscar(0, TAMANO, sBusquedaU); // Realizar la busqueda de usuarios
		}
		break;
		case 3:
		{
			string sBusquedaB;
			cout << "Ingrese el nombre, apellido o nombre completo: ";
			cin.ignore(); // Limpiar el buffer de entrada
			getline(cin, sBusquedaB); // Leer la cadena de b�squeda
			cout << "\nResultados de la busqueda:" << endl;
			gestorB.buscar(0, TAMANO, sBusquedaB); // Realizar la busqueda de usuarios
		}
		break;
		case 0:
			cout << "Volviendo al Menu Principal..." << endl;
			break;
		default:
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcionBusqueda != 0);
}
// Menu principal
void menuPrincipal(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
	int opcionPrincipal;
	do {
		cout << "\nMenu:" << endl;
		cout << "1. Llenado Datos" << endl;
		cout << "2. Listas" << endl;
		cout << "3. Busquedas" << endl;
		cout << "0. Salida" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcionPrincipal;
		cin.ignore(); //Limpiar el buffer de entrada
		switch (opcionPrincipal) {
		case 1:
			gestorL.llenar();
			gestorU.llenar();
			gestorB.llenar();
			cout << "Datos llenados exitosamente." << endl;
			break;
		case 2:
			menuListados(gestorL, gestorU, gestorB);
			break;
		case 3:
			menuBusqueda(gestorL, gestorU, gestorB);
			break;
		case 0:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcionPrincipal != 0);
}
int main() {
	srand(time(nullptr));
	// Crear instancias de los gestores de libros, usuarios y bibliotecarios
	GestorLibros gestorL;
	GestorUsuarios gestorU;
	GestorBibliotecarios gestorB;
	// Llamar a la funci�n del men� principal, pasando los gestores como argumentos
	menuPrincipal(gestorL, gestorU, gestorB);
	return 0;
}
