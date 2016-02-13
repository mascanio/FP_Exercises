#include <iostream>
using namespace std;

#include <fstream>
#include <cmath>

int main()
{
	system ("chcp 1252");

	ifstream lectura;
	ofstream escritura;

	int opcion = -1,
		generado,
		buscar,
		leido,
		linea;

	bool serieGenerada = false,
		encontrado;

	while (opcion != 0)
	{
		cout << "1 - Generar la serie" << endl 
			<< "2 - Buscar en la serie" << endl 
			<< "0 - Salir" << endl ;
		cin >> opcion;

		switch (opcion)
		{
		case 0: break;

		case 1: //Generar serie
			escritura.open ("serie.txt"); //Apertura de archivo
			generado = 1;
			for (int i = 1; i < 30; i++) //Se generan los números de la serie, se muestran y escriben en serie.txt
			{
				escritura << generado << endl;		
				cout << generado << ", " ;
				generado = pow(-1, i) * (abs (generado) + i);
			}
			escritura << generado << endl;
			cout << generado << endl;  //El último sin , en pantalla
			escritura << 0; //centinela

			escritura.close();

			serieGenerada = true;
			break;

		case 2: //Buscar en serie (se comprueba si ha sido generada)
			if (serieGenerada)
			{
				cout << "Valor a buscar (en valor absoluto): " ;
				cin >> buscar;
				buscar = abs(buscar);

				lectura.open("serie.txt"); //Abrir archivo y comprobar si abre
				if (lectura.is_open())
				{
					linea = 0;
					encontrado = false;

					lectura >> leido;
					leido = abs(leido);

					while (leido != 0 && !encontrado && leido <= buscar)
					{
						if (leido == buscar)						
							encontrado = true;
						
						else
						{
							lectura >> leido;
							leido = abs(leido);
							linea++;
						}
					}
					if (encontrado)
						cout << "Encontrado en línea: " << linea << endl ;

					else
						cout << "No se ha encontrado el valor introducido " << endl ;

					lectura.close();
				}
				else
					cout << "¡Error de apertura de archivo!" << endl ;
			}
			else
				cout << "¡Serie no generada todavía!" << endl ;

			break;
		default:
			cout << "¡Opción no válida!" << endl ;
			break;
		}
	}

	return 0;
}
