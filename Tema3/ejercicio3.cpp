#include <iostream>
using namespace std;


int main()
{
	char caracter;

	cout << "Introduzca caracter: " ;
	cin >> caracter ;

	cout << caracter ;

	if ((caracter >= '0') && (caracter <= '9'))
		cout << ": n�mero" ;
	else if ((caracter >= 'a') && (caracter <= 'z'))
		cout << ": min�scula" ;
	else if ((caracter >= 'A') && (caracter <= 'Z'))
		cout << ": may�scula" ;
	else
		cout << ": no es ni n�mero ni letra" ;

	return 0;
}
