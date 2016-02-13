#include <iostream>

using namespace std;

#include <fstream>

int main()
{
	int contador = 0;

	ifstream archivo;
	char lectura;

	bool fin = false;

	archivo.open("input26.txt");

	archivo.sync();
	do
	{	
		archivo.get(lectura);
		while (lectura == 'x')
		{
			archivo.get(lectura);
			if (lectura == 'y')
			{
				archivo.get(lectura);
				if (lectura == 'x')
				{
					contador++;
				}
			}
		}
	} while (lectura != '*');

	archivo.close();

	cout << "Contador: " << contador << endl;

	contador = 0;

	archivo.open("input26.txt");

	archivo.sync();
	do
	{	
		fin = false;
		archivo.get(lectura);
		while (lectura == 'x' && !fin)
		{
			archivo.get(lectura);
			if (lectura == 'y')
			{
				archivo.get(lectura);
				if (lectura == 'x')
				{
					contador++;
					fin = true;
				}
			}
		}
	} while (lectura != '*');

	archivo.close();

	cout << "Contador: " << contador;

	return 0;
}
