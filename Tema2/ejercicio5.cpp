// Miguel Ascanio Gómez y Javier Ortiz Iniesta
// Ejercicio 5
#include <iostream>

using namespace std;

int main()
{
	double eDic, eFeb, eAbr, eFin, p1, p2, p3, p4, p5, aAdicional, nota; //Declaraciones

	cout << "*** CALCULADOR DE NOTA FUNDAMENTOS DE PROGRAMACION ***" << endl
         << "Calculada teniendo en cuenta:" << endl
         << "\t * Prácticas:            20% " << endl
         << "\t * Examen de diciembre:   5% " << endl
         << "\t * Examen de febrero:    10% " << endl
         << "\t * Examen de abril:      10% " << endl
         << "\t * Examen final:         45% " << endl
         << "\t * Actividad adicional:  10% " << endl
         << "Introduzca las notas según se solicite a continuacion: " <<endl

    //Entrada de notas
		 << endl << "Nota del examen de diciembre: " ;
	cin  >> eDic;
	cout << "Nota del examen de febrero: " ;
	cin  >> eFeb;
	cout << "Nota del examen de abril: " ;
	cin  >> eAbr;
	cout << "Nota del examen final: " ;
	cin  >> eFin;

	cout << endl << "Nota de la práctica 1: " ;
	cin  >> p1;
	cout << "Nota de la práctica 2: " ;
	cin  >> p2;
	cout << "Nota de la práctica 3: " ;
	cin  >> p3;
	cout << "Nota de la práctica 4: " ;
	cin  >> p4;
	cout << "Nota de la práctica 5: " ;
	cin  >> p5;

	cout << endl << "Nota de la actividad adicional: " ;
	cin  >> aAdicional;

        //Formula nota final
	nota = eDic * 0.05 + eFeb * 0.1  + eAbr * 0.1 + eFin * 0.45 + ((p1 + p2 + p3 + p4 + p5) / 5) * 0.2 + aAdicional * 0.1 ;

        //Salida nota final
	cout << endl
         << "**************" << endl
         << "Nota final: " <<nota << endl
         << "**************" ;

	return 0;
}
