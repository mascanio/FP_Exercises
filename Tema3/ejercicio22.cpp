#include <iostream>
using namespace std;

#include <cmath>

int main()
{
	system("chcp 1252");

	double entrada, raiz, aproximacion;
	const double error = 10e-4;

	bool aproximacionOK = false;

	cout << "Introduzca n�mero: " ;
	cin >> entrada;

	raiz = sqrt(entrada);

	do
	{
		cout << endl << "Introduzca aproximaci�n: " ;
		cin >> entrada;

		aproximacion = entrada - raiz;

		if (abs(aproximacion) <= error)
			aproximacionOK = true;
		else if ((aproximacion - error) < 0)
			cout << "La ra�z es mayor!" ;
		else
			cout << "La ra�z es menor!" ;

	} while (!aproximacionOK);

	return 0;
}
