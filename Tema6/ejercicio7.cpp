#include <iostream>
#include <string>
using namespace std;

const int EMPLEADOS_MAX = 3;

typedef enum tEstudios
{
	ESO, Bachillerato, FpMedio, FpSuperior, Grado, Master, Doctorado,
};
typedef enum tContrato
{
	Fijo, Practicas, Eventual, Becario,
};

typedef struct 
{
	string nombre;
	string apellido1;
	string apellido2;

	int edad;

	tEstudios estudios;
	tContrato contrato;
} tEmpleado;

typedef tEmpleado tPlantilla[EMPLEADOS_MAX];

typedef struct 
{
	int contador;
	tPlantilla plantilla;
} tLista;

//Muestra el menu y pide opción. Confirmación para borrar todo
//Devuelve opción elegida como int
int menu();

//Comprueba si la string entrada pasada como parámetro es un estudio o contrato válido devolviendo un bool. Si lo es, asignia el enumerado correspondiente al empleado
bool estudiosOK(tEmpleado& empleado, string entrada);
bool contratoOK(tEmpleado& empleado, string entrada);

//Solicita al usuario los datos de un nuevo tEmpleado pasado por referecia
void datosNuevoEmpleado(tEmpleado& empleado);

// ** Las operaciones sobre el contador de tLista se realizan en los subprogramas siempre que sea necesario (salvo opciones 3 y 5) ** \\

//Desplaza la tLista pasada por referencia para poder escribir en el primer espacio sin borrar nada
void desplazar(tLista& listaEmpleados);
//Incluye en la tLista de empleados el tEmpleado empleado, por defecto al principio (se llama al procedimiento desplazar(..)), si el parametro ultimo es true lo añade al final
void incluir(tLista& listaEmpleados, tEmpleado empleado, bool ultimo = false);
//Elimina el primer empleado de la lista (mueve toda la tLista una posición atrás)
void eliminarPrimero(tLista& listaEmpleados);


int main()
{
	system("chcp 1252");

	int opcion;
	tLista listaEmpleados;
	tEmpleado empleadoAux;

	listaEmpleados.contador = 0;

	do
	{
		opcion = menu();

		switch (opcion)
		{
		case 1: //Añadir al final, comprobar si la lista está llena
			if (listaEmpleados.contador < EMPLEADOS_MAX)
			{
				datosNuevoEmpleado(empleadoAux); //Solicitar datos
				incluir(listaEmpleados, empleadoAux, true); 
			}
			else
			{
				cout << endl << "Error: la lista está llena!" << endl ;
			}
			break;

		case 2: //Añadir al principio, comprobar si la lista está llena
			if (listaEmpleados.contador < EMPLEADOS_MAX)
			{
				datosNuevoEmpleado(empleadoAux);
				incluir(listaEmpleados, empleadoAux); 
			}
			else
			{
				cout << endl << "Error: la lista está llena!" << endl ;
			}
			break;

		case 3: //Eliminar último empleado (basta con restar 1 al contador). Si el contador es 0, no hay nada que borrar (y evita contadores negativos)
			if (listaEmpleados.contador != 0)
			{
				listaEmpleados.contador--;
			}
			else
			{
				cout << endl << "Error: no hay empleados. " << endl ;
			}
			break;
		case 4: //Eliminar el primer empelado. Si el contador es 0, no hay nada que borrar (y evita contadores negativos)
			if (listaEmpleados.contador != 0)
			{
				eliminarPrimero(listaEmpleados);
			}
			else
			{
				cout << endl << "Error: no hay empleados. " << endl ;
			}
			break;
		case 5: //Eliminar todos los trabajardores: contador a 0
			listaEmpleados.contador = 0;
			cout << "Todos los empleados borrados." << endl ; 
			break;
		case -1:
			cout << "Operación borrar todo anulada" << endl ;
			break;
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

	cout << endl 
		<< "Elija una opción:" << endl 
		<< "1. Añadir empleado al final" << endl  
		<< "2. Añadir empleado al principio" << endl
		<< "3. Eliminar último empleado" << endl
		<< "4. Eliminar primer empleado" << endl
		<< "5. Eliminar todos los empleados" << endl
		<< "Opción: " ;
	cin.sync();
	cin >> opcion;

	if (opcion == 5)
	{
		cout << "¿Está seguro de que desea eliminar todos los empleados? (s/n): " ;
		cin.sync();
		cin >> car ;
		car = toupper(car);
		if (car != 'S')
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

	cout << endl 
		<< "Introduzca nombre: " ;
	cin.sync();
	getline(cin, empleado.nombre);
	cout << "Introduzca primer apellido: " ;
	cin.sync();
	getline(cin, empleado.apellido1);
	cout << "Introduzca segundo apellido: " ;
	cin.sync();
	getline(cin, empleado.apellido2);
	cout << "Introduzca edad: " ;
	cin.sync();
	cin >> empleado.edad;
	
	cout << "Introduzca estudios (ESO, Bachillerato, FpMedio, FpSuperior, Grado, Master, Doctorado): " ;
	cin.sync();
	cin >> entrada;
	//pedir dato válido
	while (!estudiosOK(empleado, entrada))
	{
	cout << "Entrada no válida. Introduzca otra: " ;
	cin.sync();
	cin >> entrada;
	}

	cout << "Introduzca contrato (Fijo, Practicas, Eventual, Becario): " ;
	cin.sync();
	cin >> entrada;
	//pedir dato válido
	while (!contratoOK(empleado, entrada))
	{
	cout << "Entrada no válida. Introduzca otra: " ;
	cin.sync();
	cin >> entrada;
	}
}

void incluir(tLista& listaEmpleados, tEmpleado empleado, bool ultimo)
{
	if (ultimo)
	{
		//Incluimos tEmpleado empleado al principio indice[contador] y lo incrementamos en 1
		listaEmpleados.plantilla[listaEmpleados.contador++] = empleado;
	}
	else
	{
		//Desplazamos a la derecha e incluimos tEmpleado empleado al principio indice[0]
		desplazar(listaEmpleados);
		listaEmpleados.plantilla[0] = empleado;
	}
}

void desplazar(tLista& listaEmpleados)
{
	//Desplazar a la derecha (el siguiente es el anterior, empezando por el final, contador - 1)
	for (int i = listaEmpleados.contador - 1; i >= 0; i--)
	{
		listaEmpleados.plantilla[i + 1] = listaEmpleados.plantilla[i];
	}
	listaEmpleados.contador++;
}

void eliminarPrimero(tLista& listaEmpleados)
{
	//Desplazo a la izquierda (el actual es el siguiente, empezando desde el primero, hasta el penúltimo, contador -1)
	for (int i = 0; i < listaEmpleados.contador - 1; i++)
	{
		listaEmpleados.plantilla[i] = listaEmpleados.plantilla[i + 1];
	}
	listaEmpleados.contador--;
}
