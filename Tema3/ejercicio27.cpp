#include <iostream>
using namespace std;

#include <cmath>
#include <iomanip>

int main()
{
	int sucesionPrevio, sucesion, terminos;

	do
	{
		cout << "Introduzca número de términos: " ;
		cin >> terminos;

	} while (terminos < 0);

	sucesion = 1;
	sucesionPrevio = 1;

	for (int i = 0; i <= terminos; i++)
	{
		sucesion = pow (-1, i) * sucesionPrevio + i;
		sucesionPrevio = sucesion;

		cout << "Término " << setw (3) << i << " = " << setw (4) << sucesion << endl ;
	}

	return 0;
}
