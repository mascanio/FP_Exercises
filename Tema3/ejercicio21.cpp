#include <iostream>
using namespace std;

int main()
{
	int entrada = 1, num;
	bool creciente = true;

	cout << "Introduzca número: " ;
	cin >> entrada;

	if (entrada != 0)
	{

		num = entrada - 1;

		while (entrada != 0 && creciente)
		{
			if (entrada >= num && entrada != 0)
			{
				num = entrada;		
				cout << "Introduzca número: " ;
				cin >> entrada;
			}
			else if (entrada != 0)
				creciente = false;
		}
		if (creciente)
			cout << "La serie es creciente." ;
		else if (!creciente)
			cout << "La serie no es creciente." ;
	}
	else
		cout << "No hay serie" ;

	return 0;
}
