/*

MIGUEL ASCANIO GÓMEZ

Ej. 0410 Números perfectos son triangulares

*/
#include <iostream>
using namespace std;
#include <ctime>

const int LIMITE = 100000;

bool esTriangular(int num);
bool esPerfecto (int num);

bool esTriangular(int num)
{
	int i = 1, contador = 0, suma = 0;

	bool salida = false;
	while (suma < num)
	{
		suma += contador;
		contador++;
	}
	return (suma == num);
}
bool esPerfecto (int num) 
{
	int i = 1, contador = 0;

	while (i < num)
	{
		if ((num % i) == 0)
			contador += i;
		i++;
	}
	return (contador == num);
}

int main()
{
	system("chcp 1252");

	int i = 1, tiempoInicio;
	bool OK = true;

	cout << "Comprobar que los números entre 1 y " << LIMITE << " que son perfectos son, además, triangulares. " << endl
		<< "Pulse intro para continuar..." << endl ;
	cin.sync();
	cin.get();

	tiempoInicio = time(NULL);

	cout << "Trabajando... " ;

	while ((i <= LIMITE) && OK)
	{
		OK = !(esPerfecto(i) && !esTriangular(i));
		i++;
	}

	cout << endl << endl << "Se ha comprobado " << (OK ? "satisfactoriamente" : "insatisfactoriamente") << " en " << time(NULL) - tiempoInicio << " segundos que todos los números entre 1 y " << LIMITE ;
	cout << " que son perfectos son, además, triangulares. " << endl << "Pulse intro para continuar..." ;
	cin.sync();
	cin.get();

	return 0;
}
