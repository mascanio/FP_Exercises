#include <iostream>
using namespace std;

int main()
{
	int entrada, acumulado = 0;

	cout << "Introduzca dos números para mostrar el mayor" << endl ;

	for (int i = 0; i < 10; i++)
	{
		cout << "Introduzca número: " ;
		cin >> entrada;

		if (entrada > acumulado)
		{
			acumulado = entrada;
		}
	}

	cout << "El número mayor introducido es: " << acumulado;
	return 0;
}
