#include <iostream>
using namespace std;

#include <fstream>

int main()
{
	char entrada = 'x';
	int contador = 0;
	bool encontrado = false;

	cout << "Introduzca secuencia de caracteres para conarlos hasta la primera a (fin con un .): " << endl;

	while (entrada != '.' && entrada != 'a')
	{
		cin >> entrada;
		if (entrada != 'a')
		{
			contador++;
		}
		else
		{
			encontrado = true;
		}
	}

	if (encontrado)
	{
		cout << "Número de caracteres: " << contador;
	}
	else
	{
		cout << "Ninguna a en la cadena";
	}

	return 0;
}
