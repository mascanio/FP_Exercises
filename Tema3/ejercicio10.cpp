#include <iostream>
using namespace std;

int main()
{
	int entrada, acumulado = 0;

	cout << "Introduzca dos n�meros para mostrar el mayor" << endl ;

	for (int i = 0; i < 10; i++)
	{
		cout << "Introduzca n�mero: " ;
		cin >> entrada;

		if (entrada > acumulado)
		{
			acumulado = entrada;
		}
	}

	cout << "El n�mero mayor introducido es: " << acumulado;
	return 0;
}
