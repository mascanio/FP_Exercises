//Miguel Ascanio G�mez Ejercicio 14 hoja 6
//Se presupone que el formatod el archivo es correcto, las comunidades est�n ordenadoas y no se repiten, 
//aunque se comprueba si los n�meros de partidos y comunidades son correctas

#include <iostream>
#include <string>
using namespace std;

#include <fstream>

const int 
	MAX_COMUNIDADES = 15,
	MAX_PARTIDOS = 10;

//	Esturcutra:
//	+ tComunidad(estructura)
//		- numPartidos de cada comunidad (int)
//		- tPartidoIndividual (array, indice accede a partido de la comunidad) tipo:
//			+tPartidoIndividual(estructura)
//			- escanios de cada partido (int)
//			- nombre del partido (string)

typedef struct tPartidoIndividual
{
	int escanios;
	string nombre;
};

typedef tPartidoIndividual tPartidos[MAX_PARTIDOS];

typedef struct tComunidad
{
	int numPartidos;
	tPartidos partidos;
};

//Procedimiento que lee del archivo ifstream y copia una l�nea entera a la estructura comunidad
bool cargarComunidad(ifstream& archivo, tComunidad& comunidad);
//Procedimiento que toma como par�metros la comunidad y el n�mero de esta, para mostrar en pantalla el partido ganador de dicha comunidad (y empates) 
void procesarComunidad(tComunidad comunidad, int numComunidad);

int main()
{
	system("chcp 1252");
	ifstream archivo;
	tComunidad comunidad;

	int leido;
	bool salir = false;

	archivo.open("archivo.txt");
	if (archivo.is_open())
	{
		do
		{
			archivo >> leido; //O bien el n�mero de comunidad, o el centinela
			if (leido != -1 && leido < MAX_COMUNIDADES)
			{
				if (cargarComunidad(archivo, comunidad)) //Si la carga se realiza correctamente
					procesarComunidad(comunidad, leido);  //Procesar comunidad (muetra en pantallla los datos)
				else
					salir = true; //error en carga, salir del bucle
			}
			else if (leido >= MAX_COMUNIDADES)
			{
				cout << "Error: sobrepas� el n�mero m�ximo de comunidades" << endl ;
			}
		} while (leido != -1 && leido < MAX_COMUNIDADES && !salir);
	}
	else
	{
		cout << "Error de apertura de archivo. " << endl ;
	}
	archivo.close();

	cout << "Pulse Enter para continuar... " ;
	cin.get();

	return 0;
}

void procesarComunidad(tComunidad comunidad, int numComunidad)
{
	tPartidos partidosGanadores; //Estructura para introducir los m�ximos esca�os (y los empatados al maximo)

	int escaniosMax = -1, escaniosAcum = 0, empates = 0;

	for (int i = 0; i < comunidad.numPartidos; i++)
	{
		escaniosAcum += comunidad.partidos[i].escanios; // Acumular para porcentajes
		if (comunidad.partidos[i].escanios >= partidosGanadores[0].escanios)
		{
			if (comunidad.partidos[i].escanios != partidosGanadores[0].escanios)
			{
				empates = -1; //Si son diferentes, y adem�s el nuevo es mayor, ponemos el leido en la pos 0 de los ganadores
			}
			empates++;
			partidosGanadores[empates].escanios = comunidad.partidos[i].escanios;
			partidosGanadores[empates].nombre = comunidad.partidos[i].nombre;
		}
	}

	cout << "Los partidos vencedores de la comunidad " << numComunidad << " son: " << endl ;

	for (int i = 0; i <= empates; i++)
	{
		cout << partidosGanadores[i].nombre << endl ;
	}

	cout << "Con un porcentaje de esca�os de: " << ((double(partidosGanadores[0].escanios) / escaniosAcum) * 100) << "%" << ((empates == 0) ? "" : " cada uno." ) << endl << endl ;

}
bool cargarComunidad(ifstream& archivo, tComunidad& comunidad)
{
	bool salida = true;
	archivo >> comunidad.numPartidos;

	if (comunidad.numPartidos < MAX_PARTIDOS && comunidad.numPartidos > 0)
	{
		for (int i = 0; i < comunidad.numPartidos; i++)
		{
			archivo >> comunidad.partidos[i].nombre;					
			archivo >> comunidad.partidos[i].escanios;
		}
	}
	else
	{
		cout << "N�mero de partidos err�neo" << endl ;
		salida = false;
	}
	return salida;
}