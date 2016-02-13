// MIGUEL ASCANIO GÓMEZ
// El programa ejectuta en main los diferentes subprogramas,
// Primero realiza la carga del archivo, luego ordena el stock
// y solicita un codigo a buscar; sólo si encuentra el elemento con ese codigo,
// permite buscar en ese elemento una entrada/salida en una fecha pedida.
// Se encontrara o no el código/fecha, muestra lso datos en pantalla y actualiza entradas y salidas,
// mostrando error de todos los elementos (no se detiene comn un primer error)
#include <iostream>
#include <string>
using namespace std;

#include <fstream>
#include <iomanip>

const int MAX = 100;
const string NOMBRE_ARCHIVO = "datos.txt";
const int TAMFECHA = 8;

typedef struct 
{
	string fecha;
	char tipo;
	unsigned int unidades;
} tDatoE_S;

typedef tDatoE_S tArrayOperacionesE_S[MAX];

typedef struct
{
	int contador;
	tArrayOperacionesE_S lista;
} tListaE_S;

typedef struct 
{
	unsigned int codigo;
	string nombre;
	double precio;
	unsigned int unidadesExistentes;

	tListaE_S operacionesE_S;
	bool actualizado;
} tProducto;

typedef tProducto tArrayStock[MAX];

typedef struct 
{
	int contador;
	tArrayStock lista;
} tStock;

// Función que lee de archivo y lo copia a la estructura. Bool que devuelve apertura correcta o no
bool leer(tStock& stock);
// Procedimiento que ordena todas las listas de entradas y salidas de todos los elementos por medio del algoritmo de la burbuja mejorado
void ordenar(tStock& stock);
// Funcion que devuelve la posicion del elemento que contiene el codigo pasado como parametro. Devuelve -1 si no se encuentra
int buscarProducto(tStock stock, int codigo);
// Funcion que busca en el elemento del codigo anteriormente introducido si hay entrada o salida en la fecha pasada por parámetro
// devuelve posición de esa fecha, si no se encuentra -1
int buscarE_S(tListaE_S lista, string fecha);
// Procedimiento que muestra en pantalla los datos de todos los elementos del stock
void mostrar(tStock stock);
// Procedimiento que actualiza el numero de elementos de cada producto del stock, teniendo en cuenta entradas, salidas y numero inicial
// errores analizados dentro del mimso
void actualizar(tStock stock);

int main()
{
	system("chcp 1252");

	int codigoBuscar, indiceCodigo, indiceFecha;

	tStock listaStock;
	string fechaBuscar;

	if (leer(listaStock))
	{
		ordenar(listaStock);

		cout << "Introduzca código a buscar: " << endl ;
		cin >> codigoBuscar;
		indiceCodigo = buscarProducto(listaStock, codigoBuscar);

		if (indiceCodigo != -1)
		{
			cout << "Encontrado con índice: " << indiceCodigo << endl 
				<< "Nombre: " << listaStock.lista[indiceCodigo].nombre << endl 
				<< "Precio: " << listaStock.lista[indiceCodigo].precio << endl << endl ;

			cout << "Introduzca fecha a buscar: " << endl ;
			cin >> fechaBuscar;

			//Compruebo formato fecha
			if (fechaBuscar.size() == TAMFECHA && fechaBuscar.at(2) == '/' && fechaBuscar.at(5) == '/')
			{
				indiceFecha = buscarE_S(listaStock.lista[indiceCodigo].operacionesE_S, fechaBuscar);

				if (indiceFecha != -1)
				{
					cout << endl << "Fecha econtrada en posición " << indiceFecha << endl << endl 

						<< "Tipo " << (listaStock.lista[indiceCodigo].operacionesE_S.lista[indiceFecha].tipo == 'E' ? "entrada" : "salida") << endl 
						<< "Unidades " << listaStock.lista[indiceCodigo].operacionesE_S.lista[indiceFecha].unidades << endl ;
				}
				else
				{
					cout << "No encontrado" << endl ;
				}
			}
			else
			{
				cout << endl << "Formato de fecha erróneo" << endl ;
			}


		}
		else
		{
			cout << "No encontrado" << endl ;
		}
		mostrar(listaStock);

		actualizar(listaStock);
	}

	return 0;
}

void ordenar(tStock& stock)
{
	//Método burbuja, natural
	tDatoE_S tmp;
	bool inter;
	int i;
	for (int a = 0; a < stock.contador; a++) //Recorro todos los productos
	{
		i = 0;
		inter = true;
		while ((i < stock.lista[a].operacionesE_S.contador - 1) && inter) //De cada producto, todas las fechas mentras no ordenado
		{
			inter = false;
			for (int j = stock.lista[a].operacionesE_S.contador - 1; j > i ; j--)
			{
				if (stock.lista[a].operacionesE_S.lista[j].fecha < stock.lista[a].operacionesE_S.lista[j - 1].fecha)
				{
					tmp = stock.lista[a].operacionesE_S.lista[j];
					stock.lista[a].operacionesE_S.lista[j] = stock.lista[a].operacionesE_S.lista[j - 1];
					stock.lista[a].operacionesE_S.lista[j - 1] = tmp;
					inter = true;
				}
			}
			if (inter)
				i++;
		}
	}
}
bool leer(tStock& stock)
{
	string fecha;
	tDatoE_S operacion;

	int codigo, numOperaciones;
	bool salida;

	ifstream archivo;
	archivo.open(NOMBRE_ARCHIVO.c_str());
	salida = archivo.is_open();
	stock.contador = 0;

	if (salida)
	{
		do
		{
			archivo >> codigo;
			if (codigo > -1) //Si no es -1, leo producto
			{
				//Datos Básicos
				stock.lista[stock.contador].codigo = codigo;
				archivo.get(); //Descarto el Intro
				getline(archivo, stock.lista[stock.contador].nombre);
				archivo >> stock.lista[stock.contador].precio;
				archivo >> stock.lista[stock.contador].unidadesExistentes;
				stock.lista[stock.contador].actualizado = false;

				stock.lista[stock.contador].operacionesE_S.contador = 0;
				numOperaciones = 0;

				do
				{
					//Leo fecha, si es X, acabó el producto
					archivo >> fecha;
					if (fecha != "X")
					{
						//Uso un tDatoE_S operacion auxiliar para reducir codigo, luego asigno el auxiliar al dato correspondiente
						operacion.fecha = fecha;
						archivo >> operacion.tipo;
						archivo >> operacion.unidades;
						stock.lista[stock.contador].operacionesE_S.lista[numOperaciones] = operacion;
						numOperaciones++;
					}
				} while (fecha != "X");
				stock.lista[stock.contador].operacionesE_S.contador = numOperaciones;
				stock.contador++;
			}
		} while (codigo > -1);
		archivo.close();
	}
	else
	{
		cout << "¡Error de apertura de archivo!" << endl ;
	}

	return salida;
}
int buscarProducto(tStock stock, int codigo)
{
	int indice = 0;

	bool encontrado = false;

	while ((indice < stock.contador) && !encontrado)
	{
		encontrado = (stock.lista[indice].codigo == codigo);
		indice++;
	}

	return (encontrado ? indice - 1 : -1);
}
int buscarE_S(tListaE_S lista, string fecha)
{
	int ini = 0, fin = lista.contador - 1, mitad;
	bool encontrado = false;
	while ((ini <= fin) && !encontrado)
	{
		mitad = (ini + fin) / 2; //Div entera
		if (fecha == lista.lista[mitad].fecha)
		{
			encontrado = true;
		}
		else if (fecha < lista.lista[mitad].fecha)
		{
			fin = mitad - 1;
		}
		else
		{
			ini = mitad + 1;
		}
	}
	return (encontrado ? mitad : -1);
}
void mostrar(tStock stock)
{
	for (int i = 0; i < stock.contador; i++)
	{
		cout << "Código: " << stock.lista[i].codigo << endl ;
		cout << "Nombre: " << stock.lista[i].nombre << endl ;
		cout << "Precio: " << stock.lista[i].precio << endl ;
		cout << "Unidades: " << stock.lista[i].unidadesExistentes << endl << endl;

		cout << "Operaciones: " << endl << endl 
			<< "-----------------------------" << endl 
			<< left << setw(3) << '|' << setw(8) << "FECHA" << setw(4) << "| E_S " << setw(11) << "| Unidades |" << endl 
			<< "-----------------------------" << endl ;

		for (int j = 0; j < stock.lista[i].operacionesE_S.contador; j++)
		{
			cout 
				<< left << setw(2) << '|' << setw(9) << stock.lista[i].operacionesE_S.lista[j].fecha 
				<< left << setw(3) << '|' << setw(3) << stock.lista[i].operacionesE_S.lista[j].tipo 
				<< left << setw(2) << '|' << setw(9) << stock.lista[i].operacionesE_S.lista[j].unidades << '|' << endl ;
		}
		cout << "-----------------------------" << endl << endl ;
	}
}
void actualizar(tStock stock)
{
	//Muestro todos los errores, por lo que si encuentro uno sigo (for)
	for (int i = 0; i < stock.contador; i++)
	{
		stock.lista[i].actualizado = true;
		for (int j = 0; j < stock.lista[i].operacionesE_S.contador; j++)
		{
			if (stock.lista[i].operacionesE_S.lista[j].tipo == 'E')
			{
				stock.lista[i].unidadesExistentes += stock.lista[i].operacionesE_S.lista[j].unidades;
			}
			//Es de salida
			else if (stock.lista[i].unidadesExistentes >= stock.lista[i].operacionesE_S.lista[j].unidades)
			{
				stock.lista[i].unidadesExistentes -= stock.lista[i].operacionesE_S.lista[j].unidades;
			}
			else
			{
				//Si tengo un error, actualizado a false
				stock.lista[i].actualizado = false;
				cout << "Error de actualización de existencias en elemento: " << endl << endl 

					<< "Código: " << stock.lista[i].codigo << endl 
					<< "Nombre: " << stock.lista[i].nombre << endl 
					<< "Precio: " << stock.lista[i].precio << endl << endl 

					<< "A día " << stock.lista[i].operacionesE_S.lista[j].fecha << endl << endl ;
			}
		}
	}
}
