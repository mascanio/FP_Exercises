#include <iostream>
using namespace std;

int main()
{
	int contadorNumero = 0, contadorMinuscula = 0, contadorMayuscula = 0;
	char entrada;

	do
	{
		cin.sync();
		cout << "Introduzca car�cter, fin con (*): " ;
		cin >> entrada;
		if ((entrada >= '0') && (entrada <= '9'))
			contadorNumero++  ;
		else if ((entrada >= 'a') && (entrada <= 'z'))
			contadorMinuscula++;
		else if ((entrada >= 'A') && (entrada <= 'Z'))
			contadorMayuscula++ ;
	} while (entrada != '*');

	cout << "***********************************" << endl 
		<< "N�meros: " << contadorNumero << endl
		<< "Minusculas: " << contadorMinuscula << endl
		<< "May�sculas: " << contadorMayuscula ;

	return 0;
}
