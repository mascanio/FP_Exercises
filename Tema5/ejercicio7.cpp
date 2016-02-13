#include <iostream>
#include <string>
using namespace std;

const int EMPLEADOS_MAX = 50;

typedef enum tEstudios
{
	ESO, Bachillerato, FpMedio, FpSuperior, Grado, Master, Doctorado,
};
typedef enum tContrato
{
	Fijo, Practicas, Eventual, Becario,
};

typedef struct tEmpleado
{
	string nombre;
	string apellido1;
	string apellido2;

	tEstudios estudios;
	tContrato contrato;
};

typedef tEmpleado tPlantilla[EMPLEADOS_MAX];

typedef struct tLista
{
	int contador;
	tPlantilla plantilla;
};

int menu();

bool estudiosOK(tEmpleado& empleado, string entrada);
bool contratoOK(tEmpleado& empleado, string entrada);

void datosNuevoEmpleado(tEmpleado& empleado);
void desplazar(tLista& listaEmpleados);
void incluir(tLista& listaEmpleados, tEmpleado empleado);
void eliminar(tLista& listaEmpleados);



int main()
{
	int opcion;
	tLista listaEmpleados;

	listaEmpleados.contador = 0;

	do
	{
		opcion = menu();

		switch (opcion)
		{
		case 1: 
			if (listaEmpleados.contador < EMPLEADOS_MAX)
			{
				desplazar(listaEmpleados);

			}

		default:
			cout << "Opción no válida." << endl ;
			break;
		}

	} while (opcion != 0);

	return 0;
}

int menu()
{
	int opcion;
	char car;

	cout << "Elija una opción:" << endl 
		<< "1. Añadir empleado al final" << endl  
		<< "2. Añadir empleado al principio" << endl
		<< "3. Eliminar último empleado" << endl
		<< "4. Eliminar primer empleado" << endl
		<< "5. Eliminar todos los empleados" << endl
		<< "opción: " ;
	cin.sync();
	cin >> opcion;

	if (opcion == 5)
	{
		cout << "¿Está seguro de que desea eliminar todos los empleados? (s/n): " ;
		cin.sync();
		cin >> car ;
		car = towupper(car);
		if (car != 's')
			opcion = -1;
	}

	return opcion;
}

bool estudiosOK(tEmpleado& empleado, string entrada)
{
	bool salida = true;

	if (entrada == "ESO")
		empleado.estudios = ESO;
	else if (entrada == "Bachillerato")
		empleado.estudios = Bachillerato;
	else if (entrada == "FpMedio")
		empleado.estudios = FpMedio;
	else if (entrada == "FpSuperior")
		empleado.estudios = FpSuperior;
	else if (entrada == "Grado")
		empleado.estudios = Grado;
	else if (entrada == "Master")
		empleado.estudios = Master;
	else if (entrada == "Doctorado")
		empleado.estudios = Doctorado;

	else
		salida = false;

	return salida;
}
bool contratoOK(tEmpleado& empleado, string entrada)
{
	bool salida = true;

	if (entrada == "Fijo")
		empleado.contrato = Fijo;
	else if (entrada == "Practicas")
		empleado.contrato = Practicas;
	else if (entrada == "Eventual")
		empleado.contrato = Eventual;
	else if (entrada == "Becario")
		empleado.contrato = Becario;

	else
		salida = false;

	return salida;
}

void datosNuevoEmpleado(tEmpleado& empleado)
{
	string entrada;

	cout << "Introduzca nombre: " ;
	getline(cin, empleado.nombre);
	cout << "Introduzca primer apellido: " ;
	getline(cin, empleado.apellido1);
	cout << "Introduzca segundo apellido: " ;
	getline(cin, empleado.apellido2);
	cout << "Introduzca estudios (ESO, Bachillerato, FpMedio, FpSuperior, Grado, Master, Doctorado): " ;
	cin >> entrada;

	while (!estudiosOK(empleado, entrada))
	{
		cout << "Entrada no válida. Introduzca otra: " ;
		cin >> entrada;
	}

	cout << "Introduzca contrato (Fijo, Practicas, Eventual, Becario): " ;
	cin >> entrada;

	while (!contratoOK(empleado, entrada))
	{
		cout << "Entrada no válida. Introduzca otra: " ;
		cin >> entrada;
	}
}

void desplazar(tLista& listaEmpleados)
{
	for (int i = listaEmpleados.contador; i >= 0; i--)
	{
		listaEmpleados.plantilla[listaEmpleados.contador + 1] = listaEmpleados.plantilla[listaEmpleados.contador];
	}
}
