#include <iostream>
using namespace std;

int main()
{
	int entrada;

	cout << "Introduzca n�mero para hallar su invertido: " ;
	cin >> entrada;
	
   cout << "El invertido de " << entrada << " es: ";

	while (entrada != 0) 
	{
		cout << entrada % 10;
		entrada /= 10;
	}


	return 0;
}
