#include <iostream>
using namespace std;


int main()
{
	char caracter;

	cout << "Introduzca caracter: " ;
	cin >> caracter ;

	cout << caracter ;

	if ((caracter >= '0') && (caracter <= '9'))
		cout << ": número" ;
	else if ((caracter >= 'a') && (caracter <= 'z'))
		cout << ": minúscula" ;
	else if ((caracter >= 'A') && (caracter <= 'Z'))
		cout << ": mayúscula" ;
	else
		cout << ": no es ni número ni letra" ;

	return 0;
}
