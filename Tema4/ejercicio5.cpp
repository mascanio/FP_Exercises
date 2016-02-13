#include <iostream>
using namespace std;

bool esMinuscula(char caracter);
bool esMayuscula(char caracter);
bool esDigito(char caracter);
bool esLetra(char caracter);
bool esAlfanumerico(char caracter);


bool esMinuscula(char caracter)
{
	return (caracter >= 'a' && caracter <= 'z');
}
bool esMayuscula(char caracter)
{
	return (caracter >= 'A' && caracter <= 'Z');
}
bool esDigito(char caracter)
{
	return (caracter >= '0' && caracter <= '9');
}
bool esLetra(char caracter)
{
	return esMinuscula(caracter) || esMayuscula(caracter);
}
bool esAlfanumerico(char caracter)
{
	return esDigito(caracter) || esLetra(caracter);
}

int main()
{
	char entrada;
	int letras = 0, alfanumericos = 0, digitos = 0, mayusculas = 0, minusculas = 0;

	do
	{
		cin >> entrada;
		if (entrada != '.')
			if(esAlfanumerico(entrada))
			{
				alfanumericos ++;
				if (esDigito(entrada))
					digitos ++;

				else if(esMinuscula(entrada))
				{
					letras ++;
					minusculas ++;
				}
				else
				{
					letras ++;
					mayusculas ++;
				}
			}
	} while (entrada != '.');

	cout << "Minúsculas: " << minusculas << endl
		<< "Mayúsculas: " << mayusculas << endl
		<< "Letras: " << letras << endl
		<< "Dígitos: " << digitos << endl
		<< "Alfanuméricos: " << alfanumericos << endl ;

	return 0;
}