#include <iostream>
using namespace std;

#include <cmath>

int main()
{
	system("chcp 1252");

	double entrada, raiz, aproximacion;
	const double error = 10e-4;

	bool aproximacionOK = false;

	cout << "Introduzca número: " ;
	cin >> entrada;

	raiz = sqrt(entrada);

	do
	{
		cout << endl << "Introduzca aproximación: " ;
		cin >> entrada;

		aproximacion = entrada - raiz;

		if (abs(aproximacion) <= error)
			aproximacionOK = true;
		else if ((aproximacion - error) < 0)
			cout << "La raíz es mayor!" ;
		else
			cout << "La raíz es menor!" ;

	} while (!aproximacionOK);

	return 0;
}
