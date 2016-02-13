#include <iostream>
using namespace std;

int main ()
{
	double entrada, coste;

	cout << "Introduzca metros cúbicos de agua: " ;
	cin >> entrada ; 

	if (entrada <= 100)
		coste = entrada * 0.15 ;
	else if (entrada <= 500)
	{
		coste = (entrada - 100) * 0.2 ;
		coste += 100 * 0.15;
	}
	else if (entrada <= 1000)
	{
		coste = (entrada - 500) * 0.35 ;
		coste += 400 * 0.20 ;
		coste += 100 * 0.15 ;
	}
	else
	{
		coste = (entrada - 1000) * 0.80 ;
		coste += 500 * 0.35 ;
		coste += 400 * 0.20 ;
		coste += 100 * 0.15 ;
	}

	cout << "Coste: " << coste << " €"  ;
	return 0;
}