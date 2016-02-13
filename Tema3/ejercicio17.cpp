#include <iostream>
using namespace std;

#include <fstream>

int main()
{
	ifstream archivo;
	int entrada = 1, acumulado = 0;

	archivo.open("datos.txt");

	if (archivo.is_open())
	{
		while (entrada != 0)
		{
			archivo >> entrada;

			if ((entrada > acumulado) && entrada > 0)
			{
				acumulado = entrada;
			}
		}
	}
	else
	{
		cout << "Error de apertura!" ;
	}

	cout << "El número mayor del archivo datos.txt es: " << acumulado ;

	archivo.close();

	return 0;
}
