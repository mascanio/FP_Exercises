#include <iostream>
using namespace std;

#include <fstream>

int main()
{
	system ("chcp 1252");

	const char centinela = '.';

	ifstream archivo;

	char entrada;
	int contador = 0;

	archivo.open("parking.txt"); //Se abre el archivo y se comprueba (si no, se muestra error y fin)

	if (archivo.is_open())
	{
		archivo >> entrada;
		while(entrada != centinela)
		{
			contador = 0;
			if (entrada != centinela)
			{
				while (entrada != centinela)
				{
					if (entrada == 'E')
						contador++;
					else
						contador--;

					archivo >> entrada;
				} 
				if (contador >= 0)
					cout << "Quedan " << contador << " coches." << endl ;				
				else
					cout << "Error: más salidas que entradas." << endl ;
			}
			archivo >> entrada;
		}

		archivo.close();
	}
	else
		cout << "¡Error de apertura de archivo!" ;

	return 0;
}
