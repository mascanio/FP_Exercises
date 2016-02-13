#include <iostream>
using namespace std;

int main()
{
	int contadorNumero = 0, contadorLetra = 0, contadorEspacio = 0;
	char entrada;
	bool parentesisEncontrado = false, fin = false;

	while (!fin)
	{
		cout << "Introduzca secuencia de caracteres para conarlos hasta la primera a (fin con un .): " << endl;

		contadorEspacio = 0;
		contadorLetra = 0;
		contadorNumero = 0;
		parentesisEncontrado = false;

		cin.sync();
		cin.get(entrada);

		if (entrada != '.')
		{
			while (entrada != '.' && !parentesisEncontrado)
			{
				cin.get(entrada);

				if (entrada == '(' )
				{
					while (entrada != ')' && entrada != '.' )
					{
						parentesisEncontrado = true;
						if ((entrada >= '0') && (entrada <= '9'))
							contadorNumero++  ;
						else if (((entrada >= 'a') && (entrada <= 'z')) 
							|| ((entrada >= 'A') && (entrada <= 'Z')) )
							contadorLetra++;
						else if (entrada == ' ')
							contadorEspacio++ ;

						cin.get(entrada);
					}
				}
			}

			cout << "***********************************" << endl 
				<< "Espacios: " << contadorEspacio << endl
				<< "Números: " << contadorNumero << endl
				<< "Letras: " << contadorLetra << endl << endl;
		}

		else
			fin = true;
	}

	return 0;
}
