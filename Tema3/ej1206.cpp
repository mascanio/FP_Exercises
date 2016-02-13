#include <iostream>
using namespace std;

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>

int main()
{
	srand(time(NULL));

	ifstream lectura;
	ofstream escritura;

	int opcion = -1, num, acumulado = 0, busqueda, contador;

	bool generado = false, encontrado,
		triangularEjecutado = false, busquedaEjecutado = false,
		ejecutar = false;

	do
	{
		if(opcion ==  1) //Generar secuencia
		{ 
			escritura.open("datos.txt");

			for (int i = 0; i < 100; i++)
			{

				escritura << (rand() % 10000) + 1 << endl;
			}
			escritura << -1 ;

			escritura.close();

			generado = true;
			triangularEjecutado = false;
			busquedaEjecutado = false;
			ejecutar = true;
		}

		else if(opcion == 2 && generado && ejecutar) //Triangular (si se ha generado y no ejecutado triangular y busqueda)
		{ 
			lectura.open("datos.txt");
			acumulado = 0;
			do
			{
				acumulado = 0;
				lectura >> num;
				if (num != -1)
					for(int i = 0; acumulado < num; i++) //Triangular
					{
						acumulado += i;
						if (acumulado == num)
							cout << setw(5) << num << " es triangular" << endl ;
						else if (acumulado > num)
							cout << setw(5) << num << " no es triangular" << endl ; 
					}
			}while(num != -1);

			lectura.close();
			triangularEjecutado = true;
		}

		else if (opcion == 3 && generado && ejecutar) //Busqueda (si se ha generado y no ejecutado triangular y busqueda)
		{ 
			do //pedir numero en rango 1 10000
			{
				cout << "Introduzca un número entre 1 y 10000: " ;
				cin >> busqueda;
			}while (busqueda < 1 || busqueda > 10000); 

			lectura.open("datos.txt");

			encontrado = false;
			num = 0;
			contador = 0;

			while(num != -1 && !encontrado) //busqueda del numero mayor o igual
			{
				lectura >> num;
				contador++;
				if (num >= busqueda)
				{
					encontrado = true;
					cout << busqueda << " encontrado en la línea " << contador << endl;
				}	
			}
			if(!encontrado)
				cout << "No encontrado" << endl;

			lectura.close();
			busquedaEjecutado = true;
		}

		//Menu

		cout << "1 - Generar una secuencia" << endl
			<< "2 - Procesar la secuenca" << endl
			<< "3 - Buscar en la secuencia" << endl
			<< "0 - Salir" << endl ;
		cin >> opcion;

		if (opcion > 1 && opcion < 3)
		{
			//Si se han ejecutado triangular y busqueda, necesitar regenerar la secuencia
			if(triangularEjecutado && busquedaEjecutado && opcion != 1)
			{
				cout << "Vuelva a generar la secuencia" << endl ;
				ejecutar = false;
			}
			//Si se elige triangular o busqueda y no se ha generado, pedir
			else if(opcion == 2 || opcion == 3 && !generado)
				cout << "Genere la secuencia" << endl ;
		}

	}while (opcion != 0);

	return 0;
}