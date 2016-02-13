#include <iostream>
using namespace std;

#include <fstream>

int main()
{
	system ("chcp 1252");

	ifstream archivo;

	int entrada, adivinar, intentosLimite, intentosRealizados = 0, 
		limiteInf = 1, limiteSup = 100;

	bool fin = false;

	archivo.open("datos.txt");

	if (archivo.is_open())
	{
		archivo >> adivinar >> intentosLimite; //Leer datos
		archivo.close();

		do //while (!fin)
		{
			do //while (entrada < limiteInf || entrada > limiteSup)
			{
				cout << "Introduce un entero entre " << limiteInf << " y " << limiteSup << ": " ;
				cin >> entrada;
			} while (entrada < limiteInf || entrada > limiteSup);

			if (entrada == adivinar)
			{
				cout << "¡Has acertado en " << intentosRealizados << " intentos " << endl ;
				fin = true;
			}		
			else if (entrada <= adivinar)
			{
				cout << entrada << " es menor que el valor secreto " << endl ;
				limiteInf = entrada;
			}
			else
			{
				cout << entrada << " es mayor que el valor secreto " << endl ;
				limiteSup = entrada;
			}

			intentosRealizados++;
			//Superado limite intentos?
			if (intentosLimite == intentosRealizados && !fin)
			{
				cout << "¡Has agotado todos tus intentos!" << endl ;
				fin = true;
			}
		} while (!fin);
	}
	else
		cout << "¡Error de apertura!" ;

	return 0;
}