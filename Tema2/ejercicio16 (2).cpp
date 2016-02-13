//Ejercicio 16

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numero = 1; //Declaración

    cout << "*****************************" << endl
         << "DIFERENCIADOR PARES E IMPARES" << endl
         << "*****************************" << endl ;
	
	while (0 != numero)
	{
		cout << "Introduzca el numero: ";
		cin >> numero;

		if (0 < numero)
		{
			if(numero % 2 == 0)
				cout << numero << " es par " << endl;
			else 
				cout << numero << " es impar " << endl;
		}

	}
	
	return 0;
}
