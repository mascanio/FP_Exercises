//Ejercicio 13

#include <iostream>
using namespace std;

int main()
{
    int numero1, numero2, numero3, tmp; //Declaraciones

        //Entrada de numeros a ordenar
    cout << "****************************" << endl
         << "ORDENADOR DE N�MEROS ENTEROS" << endl
         << "****************************" << endl <<endl
         << "Introduzca tres n�meros (enteros) para ordenarlos de menor a mayor" << endl << endl
         << "Introduzca el primer n�mero: " ;
    cin >> numero1 ;
    cout << "Introduzca el segundo n�mero: " ;
    cin >> numero2 ;
    cout << "Introduzca el tercer n�mero: " ;
    cin >> numero3 ;
    cout << endl
         << "****************************" << endl << endl;

	if(numero2 < numero1)
	{
		tmp = numero2 ;
		numero2 = numero1 ;
		numero1 = tmp ;
	}
	
	if(numero3 < numero1)
	{
		tmp = numero3 ;
		numero3 = numero1 ;
		numero1 = tmp ;
	}

	if(numero3 < numero2)
	{
		tmp = numero3 ;
		numero3 = numero2 ;
		numero2 = tmp ;
	}

	cout << numero1 << ", " << numero2 << ", " << numero3 ;

	return 0 ;

}
