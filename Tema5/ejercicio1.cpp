#include <iostream>
using namespace std;

const int TAM = 10;
const double NOTAMIN = 5.0;

typedef double tCalificaciones[TAM];

void leerNotas(tCalificaciones notas);
void mostrar(tCalificaciones notas);
double media(tCalificaciones notas);
int suspensos(tCalificaciones notas);

void leerNotas(tCalificaciones notas)
{
	for (int i = 0; i < TAM; i++)
	{
		cout << "Introduzca nota " << i + 1 << " " ;
		do
		{
			cin >> notas[i];
		} while (notas[i] < 0.0 || notas[i] > 10.0);
	}
}

void mostrar(tCalificaciones notas)
{
	for (int i = 0; i < TAM; i++)
		cout << notas[i] << endl ;
}

double media(tCalificaciones notas)
{
	double salida = 0.0;
	for (int i = 0; i < TAM; i++)
		salida += notas[i];

	return salida / TAM;
}

int suspensos(tCalificaciones notas)
{
	int sus = 0;
	for (int i = 0; i < TAM; i++)
	{
		if (notas[i] < NOTAMIN)
		{
			sus++;
		}
	}
	return sus;
}

int main()
{
	tCalificaciones notas;

	int susp, aprobados;

	leerNotas(notas);
	mostrar(notas);
	cout << media(notas) << endl ;
	
	susp =  suspensos(notas);
	aprobados = TAM - susp;

	cout << "Suspensos: " << susp << endl
		<< "Aprobadoos: " << aprobados ;

	return 0;
}