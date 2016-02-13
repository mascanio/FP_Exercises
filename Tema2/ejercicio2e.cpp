// Grupo01
// Miguel Ascanio Gómez y Javier Ortiz Iniesta
//
// *** ejercicio2e ***
//---------------------

#include <iostream>
#include <string>
using namespace std ;

#include <cmath>

int main()
{
    double cuota, capital, ratio, ratioAnual; //Declaraciones
    int plazo, edad, nif ;
    string nombre, apellido ;
    char letraNif ;

    cout << "*********************" << endl
         << "CALCULADOR DE NOMINAS" << endl
         << "*********************" << endl

         << "Introduzca su nombre: " ;
    cin >> nombre ;

    cout << "Introduzca su primer apellido: " ;
    cin >> apellido ;

    cout << "Introduzca su edad: " ;
    cin >> edad ;

    cout << endl << "Introduzca su NIF: " ;
    cin >> nif ;

    cout << "Introduzca la letra del NIF: " ;
    cin >> letraNif ;

    cout << "----------------------------------" << endl << endl
         << "Introduzca capital: " ;
    cin >> capital;

    cout << "Años de prestamo: " ;
    cin >> plazo ;

    //Salida
    cout << endl << "----------------------------------" << endl << endl
         << "Cliente: " << nombre << " " << apellido << " (" << edad << " años)" << endl
         << "N.I.F.: " << nif << "-" << letraNif << endl
         << endl << "********************************************" << endl;

        //Al 2,25 %
    ratioAnual = 2.25 ;

    ratio = ratioAnual / 12 ; //Al 2,25%
    cuota = (capital * ratio)  / (100 * (1 - pow(1 + ratio / 100, -plazo * 12) )) ;

    cout << "Al "<< ratioAnual << "% la cuota mensual seria de: " << cuota << endl ;

        //Al 2,5 %
    ratioAnual = 2.50 ;

    ratio = ratioAnual / 12 ;
    cuota = (capital * ratio)  / (100 * (1 - pow(1 + ratio / 100, -plazo * 12) )) ;

    cout << "Al "<< ratioAnual << "%  la cuota mensual seria de: " << cuota << endl ;

        //Al 2,75 %
    ratioAnual = 2.75 ;

    ratio = ratioAnual / 12 ;
    cuota = (capital * ratio)  / (100 * (1 - pow(1 + ratio / 100, -plazo * 12) )) ;

    cout << "Al "<< ratioAnual << "% la cuota mensual seria de: " << cuota << endl

         << "*******************************************" ;

    return 0;

}
