#include <iostream>
using namespace std;

int main()
{
	int contadorNumero = 0, contadorMinuscula = 0, contadorMayuscula = 0, contadorEspacio = 0;
	char entrada = 'a';

	cout << "Introduzca carácter: " ;

	while (entrada != '\n')
	{
		cin.get(entrada);

		if ((entrada >= '0') && (entrada <= '9'))
			contadorNumero++  ;
		else if ((entrada >= 'a') && (entrada <= 'z'))
			contadorMinuscula++;
		else if ((entrada >= 'A') && (entrada <= 'Z'))
			contadorMayuscula++ ;
		else if (entrada == ' ')
			contadorEspacio++;
	}

	cout << "***********************************" << endl 
		<< "Espacios: " << contadorEspacio << endl
		<< "Números: " << contadorNumero << endl
		<< "Minusculas: " << contadorMinuscula << endl
		<< "Mayúsculas: " << contadorMayuscula ;

	return 0;
}
