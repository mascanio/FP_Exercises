#include <iostream>
using namespace std;

#include <iomanip>

int main()
{
	system ("chcp 1252");

	int entrada, i, cubo, cuadrado, cuboAnterior, cuadradoAnterior;

	do
	{
		cout  << "Introduzca número positivo mayor o igual a 0: " ;
		cin >> entrada;
		cout << endl;

	} while (entrada < 0);

	i = 0;
	cuboAnterior = 0; 
	cuadradoAnterior = 0;

	do
	{
		cuadrado = cuadradoAnterior + i + i + 1;
		cubo = cuboAnterior + cuadradoAnterior + cuadradoAnterior + cuadradoAnterior + i + i + i + 1;

		if (cubo <= entrada)
			cout << "El cubo de " << setw (4) << i + 1 << " (" << cubo << setw (6) << ") NO es mayor que " << setw (6) << entrada << endl ;
		else
			cout << "El cubo de " << setw (4) << i + 1 << " (" << cubo << setw (6) << ") SÍ es mayor que " << setw (6) << entrada << endl ; 

		cuadradoAnterior = cuadrado;
		cuboAnterior = cubo;
		i++;

	}while (cubo <= entrada);

	return 0;
}
