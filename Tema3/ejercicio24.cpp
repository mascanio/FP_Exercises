#include <iostream>
#include <string>

using namespace std;

#include <fstream>
#include <iomanip>

int main()
{
	int i, acumulado, num;

	ifstream lectura;

	lectura.open("enteros.txt");

	acumulado = 0;
	do
	{
		acumulado = 0;
		lectura >> num;
		if (num != -1)

			i = 0;
		while (acumulado < num) //Triangular
		{
			acumulado += i;
			if (acumulado == num)
				cout << setw(5) << num << " es triangular hasta " << i << endl ;
			else if (acumulado > num)
				cout << setw(5) << num << " no es triangular" << endl ; 
			i++;
		}

	}while(num != 0);

	lectura.close();

	return 0;
}
