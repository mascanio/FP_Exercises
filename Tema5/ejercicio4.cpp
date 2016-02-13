#include <iostream>
#include <string>
using namespace std;

#include <cstring>
#include <iomanip>

const int TAM = 27;

typedef char tCadena[TAM];

typedef struct tPermutacion
{
	tCadena directa;
	tCadena inversa;
};

void inicializar(tCadena cadena);
int menu();

void string_to_Cstring(tCadena cadenaC, string cadenaStr);
bool esPermutacion (tPermutacion& permutacion);

string encriptar(string cadenaAEncriptar, tCadena permutacion);

////////////////////////////////////////////////////////////////////

int main()
{
	system("chcp 1252");

	tPermutacion permutacion;

	inicializar(permutacion.directa);
	inicializar(permutacion.inversa);

	string entrada;
	int opcion;
	bool permutacionOK, salir;

	do
	{
		permutacionOK = false;
		do
		{
			cout << endl 
				<<  "Introduzca permutación (0 para salir): " << endl ;
			cin >> entrada;
			salir = entrada != "0";
			if (!salir)
			{
				if (entrada.size() == TAM - 1)
				{
					string_to_Cstring(permutacion.directa, entrada);
					permutacionOK = esPermutacion(permutacion);

					if (!permutacionOK)
						cout << "No es una permutación válida: repite algún caracter o caracter inválido." << endl ;
				}
				else
					cout << "No es una permutación válida: no hay 26 caracteres." << endl ;
			}
		} while (!permutacionOK);

		if (!salir)
		{
			do
			{
				opcion = menu();
				cout << endl ;
				switch (opcion)
				{
				case 1:
					cout << "Introduzca texto a encriptar: " ;
					cin.sync();
					getline(cin, entrada);
					cout << encriptar(entrada, permutacion.directa);
					break;
				case 2:
					cout << "Introduzca texto a desencriptar: " ;
					cin.sync();
					getline(cin, entrada);
					cout << encriptar(entrada, permutacion.inversa);
					break;
				case 3:
				case 0: 
					break;
				default:
					cout << "Opción no válida." << endl ;
					break;
				}
			} while (opcion != 0 && opcion != 3);
			//si opción 3, vuelve a pedir clave; si 0, fin
		}
	} while (opcion != 0 && !salir);

	return 0;
}

////////////////////////////////////////////////////////////////////

void inicializar(tCadena cadena)
{
	for (int i = 0; i < TAM; i++)
		cadena[i] = '\0';
}
int menu()
{
	int opcion;

	do
	{
		cout << endl 
			<< "Seleccione opción: " << endl
			<< "1. Encriptar" << endl
			<< "2. Desencriptar" << endl
			<< "3. Cambiar clave" << endl
			<< "0. Salir" << endl
			<< "Opción: " ;
		cin.sync();
		cin >> opcion ;
	} while (opcion < 0 || opcion > 4);

	return opcion;
}

void string_to_Cstring(tCadena cadenaC, string cadenaStr)
{
	for (int i = 0; i < TAM; i++)
		cadenaC[i] = toupper(cadenaStr[i]);	
}
bool esPermutacion (tPermutacion& permutacion)
{
	bool salida = true;
	int i = 0, indice;
	inicializar(permutacion.inversa);

	for (int i = 0; i < TAM; i++) //Llenar inversa
	{
		indice = int (permutacion.directa[i]) - 'A' ;
		permutacion.inversa[indice] = char(i + 'A');
	}

	while (i < (TAM - 1)  && salida) //Comprobar si algún carácter repetido (alguna posición de la inversa estará a \0, omitiendo la final)
	{
		salida = permutacion.inversa[i] != '\0' ;
		i++;
	}

	return salida;
}
string encriptar(string cadenaAEncriptar, tCadena permutacion)
{
	string salida = "" ;
	int tamString = cadenaAEncriptar.size();

	for (int i = 0; i < tamString; i++)
	{
		if (isalpha(cadenaAEncriptar[i]))
		{
			if (islower(cadenaAEncriptar[i]))
			{
				salida += char(tolower(permutacion[int(toupper(cadenaAEncriptar[i])) - int('A')]));
			}
			else
			{
				salida += char(permutacion[int(cadenaAEncriptar[i]) - int('A')]);
			}
		}
		else
		{
			salida += cadenaAEncriptar[i];
		}
	}
	return salida;
}

