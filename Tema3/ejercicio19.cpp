#include <iostream>
using namespace std;

int main()
{
	int entrada, impar, resultado = 0;

	cout << "Introduzca número para calcular su cuadrado: " ;
	cin >> entrada;

	for (int i = 0; i < entrada; i++)
	{
		impar = 2 * i + 1;
		
		cout << impar;
		if ((i + 1) != entrada)		
			cout << " + " ;		

		resultado += impar;
	}

	cout << " = " << resultado; 

	return 0;
}
