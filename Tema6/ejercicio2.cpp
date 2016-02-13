#include <iostream>
#include <string>
using namespace std;

#include <cmath>

const int DIMENSION = 3 ;

typedef double tVector [DIMENSION] ;

int menu();

void introducirComponentes(tVector vector);
void mostrar(tVector vector);
void mostrarResultado(tVector a, tVector b, tVector resultado, string operador);

void suma (tVector a, tVector b, tVector resultado);
void resta (tVector a, tVector b, tVector resultado);
double productoEscalar(tVector a, tVector b);
double modulo(tVector a);
void normalizar(tVector a, tVector resultado);
double mayorComponente(tVector a);

/////////////////////////////////////////////////////////////////////////////////////

int menu()
{
	int opcion;

	cout << "1. Suma de vectores" << endl
		<< "2. Resta de vectoores" << endl
		<< "3. Módulo de un vector" << endl 
		<< "4. Producto escalar de 2 vectores" << endl 
		<< "5. Normalización de un vecctor" << endl
		<< "6. Obtención de la componente de mayor valor" << endl
		<< "0. Salir" << endl ;

	cin >> opcion ;

	return opcion;
}
void introducirComponentes(tVector vector)
{
	for (int i = 0; i < DIMENSION; i++)
	{
		cout << "Introduzca componente " << i << ": " ;
		cin >> vector[i];
	}
}
void mostrar(tVector vector)
{
	for (int i = 0; i < DIMENSION; i++)
	{
		cout << vector[i] << (i != DIMENSION - 1 ? ", " : "");
	}
}
void mostrarResultado(tVector a, tVector b, tVector resultado, string operador)
{
	cout << endl 
		<< "=================================" << endl 
		<< "(" ;
	mostrar(a);
	cout << ") " << operador << " (" ;
	mostrar(b);
	cout << ") = (" ;
	mostrar(resultado) ;
	cout << ")" << endl 
		<< "=================================" << endl << endl ;
}

void suma (tVector a, tVector b, tVector resultado)
{
	for (int i = 0; i < DIMENSION; i++)
	{
		resultado[i] = a[i] + b[i];
	}
}
void resta (tVector a, tVector b, tVector resultado)
{
	for (int i = 0; i < DIMENSION; i++)
	{
		resultado[i] = a[i] - b[i];
	}
}
double productoEscalar(tVector a, tVector b)
{
	double resultado = 0;
	for (int i = 0; i < DIMENSION; i++)
	{
		resultado += a[i] * b[i];
	}
	return resultado;
}
double modulo(tVector a)
{
	double salida = 0;

	for (int i = 0; i < DIMENSION; i++)
	{
		salida += pow(a[i], 2);
	}
	return sqrt(salida);
}
void normalizar(tVector a, tVector resultado)
{
	double mod = modulo(a);

	for (int i = 0; i < DIMENSION; i++)
	{
		resultado[i] = a[i] / mod;
	}
}
double mayorComponente(tVector a)
{
	double num = a[0]; //en caso de que la mayor sea la primera 

	for (int i = 1; i < DIMENSION; i++)
	{
		if (a[i] >= a[i-1])
			num = a[i];
	}
	return num;
}

int main()
{
	system ("chcp 1252");
	
	tVector a, b, resultado;
	
	int opcion;
	
	do
	{
		opcion = menu();

		switch (opcion)
		{
		case 1: 
			cout << endl << "Introduzca primer vector" << endl ;
			introducirComponentes(a);
			cout << endl << "Introduzca segundo vector" << endl ;
			introducirComponentes(b);

			suma(a, b, resultado);

			mostrarResultado(a, b, resultado, "+");

			break;

		case 2:
			cout << endl << "Restar segundo vector al primero. " << endl 
				<< "Introduzca primer vector" << endl ;
			introducirComponentes(a);
			cout << endl << "Introduzca segundo vector" << endl ;
			introducirComponentes(b);

			resta(a, b, resultado);

			mostrarResultado(a, b, resultado, "-");

			break;

		case 3:

			cout << endl << "Introduzca vector" << endl ;
			introducirComponentes(a);

			cout << endl << "==================" << endl
				<< "Módulo de (" ;
			mostrar(a);
			cout << ") = " << modulo(a) << endl << "==================" << endl << endl ;

			break;

		case 4:
			cout << endl << "Restar segundo vector al primero. " << endl 
				<< "Introduzca primer vector" << endl ;
			introducirComponentes(a);
			cout << endl << "Introduzca segundo vector" << endl ;
			introducirComponentes(b);


			cout << endl 
				<< "=================================" << endl 
				<< "(" ;
			mostrar(a);
			cout << ") * (" ;
			mostrar(b);
			cout << ") = " <<	productoEscalar(a, b) << endl 
				<< "=================================" << endl << endl ;

			break;

		case 5:

			cout << endl << "Introduzca vector" << endl ;
			introducirComponentes(a);

			normalizar(a, resultado);

			cout << endl << "==================" << endl 
				<< "Unitario de (" ;
			mostrar(a);
			cout << ") = (" ;
			mostrar(resultado);
			cout << ")" << endl 
				<< "==================" << endl << endl ;

			break;

		case 6:

			cout << endl << "Introduzca vector" << endl ;
			introducirComponentes(a);

			cout << endl 
				<< "==================" << endl 
				<< "Mayor componente de (" ;
					mostrar(a);
					cout << ") = "	<< mayorComponente(a) << endl 
				<< "==================" << endl << endl ;

			break;

		case 0: break;

		default:
			cout << "¡Opción no válida" << endl ;
			break;
		}
	} while (opcion != 0);

	return 0;
}