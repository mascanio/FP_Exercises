//Ejercicio 14

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cadena1, cadena2, cadena3, tmp; //Declaraciones

        //Entrada de cadenas a ordenar
    cout << "*******************************" << endl
         << "ORDENADOR CADENAS DE CARACTERES" << endl
         << "*******************************" << endl <<endl
         << "Introduzca tres cadenas de caracteres para ordenarlas de menor a mayor" << endl << endl
         << "Introduzca la primera cadena: " ;
    cin >> cadena1 ;
    cout << "Introduzca la segunda cadena: " ;
    cin >> cadena2 ;
    cout << "Introduzca la tercera cadena: " ;
    cin >> cadena3 ;
    cout << endl
         << "****************************" << endl << endl;

	if(cadena2 < cadena1)
	{
		tmp = cadena2 ;
		cadena2 = cadena1 ;
		cadena1 = tmp ;
	}
	
	if(cadena3 < cadena1)
	{
		tmp = cadena3 ;
		cadena3 = cadena1 ;
		cadena1 = tmp ;
	}

	if(cadena3 < cadena2)
	{
		tmp = cadena3 ;
		cadena3 = cadena2 ;
		cadena2 = tmp ;
	}

	cout << cadena1 << ", " << cadena2 << ", " << cadena3 ;

	return 0 ;

}
