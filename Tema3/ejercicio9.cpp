#include <iostream>
using namespace std;

int main()
{
	int sumaMagico, entrada, suma = 0;
	bool entrar = true; //forzar a entrar el bucle

	cout << "Introduce número para calcular su número mágico: " ;
	cin >> entrada;

	sumaMagico = entrada;

	while (sumaMagico > 9 || entrar)
	{
		entrar = false; //no seguir forzando el bucle
		while (sumaMagico != 0)//calculo del número mágico
		{
			suma += sumaMagico % 10;
			sumaMagico /= 10;
		}
		sumaMagico = suma;
		suma = 0;
	}

	cout << "El número mágico de " << entrada << " es: " << sumaMagico;

	return 0;
}
