#include <iostream>
using namespace std;

#include <cmath>
#include <iomanip>

int main()
{
	system ("chcp 1252");

	int entrada, i;

	do
	{
		cout  << "Introduzca número positivo mayor o igual a 0: " ;
		cin >> entrada;
		cout << endl;

	} while (entrada < 0);

	i = 0;

	while (pow (i - 1, 3) <= entrada)
	{
		if (pow (i, 3) <= entrada)
			cout << "El cubo de " << setw (4) << i << " (" << pow (i, 3) << setw (6) << ") NO es mayor que " << setw (6) << entrada << endl ;
		else
			cout << "El cubo de " << setw (4) << i << " (" << pow (i, 3) << setw (6) << ") SÍ es mayor que " << setw (6) << entrada << endl ; 

		i++;
	}

	return 0;
}
