#include <iostream>
using namespace std;

int main()
{
	int numeroUno, numeroDos, resultado = 0; 

	cout << "Introduzca dos n�meros (enteros positivos) para multiplicarlos" << endl ;

	do
	{
		cout << "N�mero uno: " ;
		cin >> numeroUno ;
	} while (numeroUno < 0);

		do
	{
		cout << "N�mero dos: " ;
		cin >> numeroDos ;
	} while (numeroDos < 0);

	for (int i = 0; i < numeroDos; i++)
	{
		resultado += numeroUno;
	}
	cout << "Resultado = " << resultado;

	return 0;
}
