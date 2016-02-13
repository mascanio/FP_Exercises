#include <iostream>
#include <fstream>

using namespace std;
#include <iomanip>

const int NIF = 10;
const int NOMBRE_DIR = 120;
const int MAX = 100;

typedef char cadenaNif[NIF];
typedef char cadenaNombre_Dir[NOMBRE_DIR];


typedef struct{
	cadenaNif nif; //(cadena al estilo de C de 10 caracteres)
	cadenaNombre_Dir nombre; //(cadena al estilo de C de hasta 120 caracteres)
	int edad; //(entero)
	cadenaNombre_Dir dirección; //(cadena al estilo de C de hasta 120 caracteres)
	double sueldo; //(real)
	bool casado; //(bool)
	int hijos; //(entero)
}tEmpleado;

const int SIZE = sizeof(tEmpleado);

typedef tEmpleado *ptrEmpleado;

typedef struct {
	int contador;
	ptrEmpleado empleado;
}tListaEmpleados;

// Prototipos
bool leerTxt(tListaEmpleados &empleados);
void guardar(tListaEmpleados empleados);
bool leerBin(tListaEmpleados &empleados);
void mostrar(tListaEmpleados empleados);

int main(){
	system ("chcp 1252");
	bool ok;
	tListaEmpleados empleados;

	ok = leerTxt(empleados);
	mostrar(empleados);
	cout << "================" << endl ;
	guardar(empleados);
	ok = leerBin(empleados);
	mostrar(empleados);
	delete [] empleados.empleado;
return 0;
}

//Funciones

bool leerTxt(tListaEmpleados &empleados){
ifstream archivo;
bool leido = false;
char c;
int op, i = 0;
tEmpleado aux;
archivo.open("empleados.txt");

	if (!archivo.is_open()){
		cout << "ERROR al abrir el archivo empleados.txt." << endl;
	}
	else{

		empleados.empleado = new tEmpleado[MAX];

	leido = true;
	archivo.getline(aux.nif, 10);
		while ((strcmp(aux.nif, "X") != 0) && (i < MAX)){
			archivo.getline(aux.nombre, NOMBRE_DIR);
			archivo >> aux.edad;
			archivo.get(c);
			archivo.getline(aux.dirección, NOMBRE_DIR);
			archivo >> aux.sueldo;
			archivo >> op;
			aux.casado = (op == 1);

			archivo >> aux.hijos;
			empleados.empleado[i] = aux;
			i++;
			archivo.get(c);
			archivo.getline(aux.nif, NIF);
		}
		empleados.contador = i;
	}
	archivo.close();
	return leido;
}

void guardar(tListaEmpleados empleados){
	fstream archivo;
	archivo.open("listaEmpleados.dat", ios::out | ios::binary | ios::trunc); // abrimos el archivo binario
	for (int i = 0; i < empleados.contador; i++){
		archivo.write((char *) &empleados.empleado[i], SIZE);
	}
	archivo.close();
}

bool leerBin(tListaEmpleados &empleados){
	fstream archivo;
	int pos, tam;
	bool salida = false;
	archivo.open("listaEmpleados.dat", ios::in | ios::binary); // abrimos el archivo binario
	if (!archivo.is_open()){
	cout << "ERROR al abrir el archivo listaEmpleados.dat" << endl;
	}
	else{
		salida = true;
		archivo.seekg(0,ios::end);
		pos = archivo.tellg();
		tam = pos/SIZE;
		archivo.seekg(0, ios::beg);
		for(int i = 0; i < tam; i++){
			archivo.read((char*) &empleados.empleado[i], SIZE);
		}
	}
	archivo.close();
return salida;
}

void mostrar(tListaEmpleados empleados){
	for (int i = 0; i < empleados.contador; i++){
	
			cout << empleados.empleado[i].nif << endl;
			cout << empleados.empleado[i].nombre << endl;
			cout << empleados.empleado[i].edad << endl;
			cout << empleados.empleado[i].dirección<< endl;
			cout << setprecision(9) << empleados.empleado[i].sueldo<< endl;
			cout << empleados.empleado[i].casado<< endl;
			cout << empleados.empleado[i].hijos<< endl;
			cout << endl;
	}
}