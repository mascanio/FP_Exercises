#include <iostream>
using namespace std;

int main()
{
	int division, entrada, suma = 0;
	bool entrar = true; //forzar a entrar el bucle

	cout << "Introduce n�mero para calcular la suma de sus d�gitos: " ;
	cin >> entrada;

	division = entrada;
	
	while (division != 0) 
	{
		suma += division % 10;
		division /= 10;
	}
	
	cout << "La suma de las cifras de " << entrada << " es: " << suma; 

	return 0;
}
