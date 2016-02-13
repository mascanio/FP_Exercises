// Grupo01
// Miguel Ascanio Gómez y Javier Ortiz Iniesta
//
// *** Tema02 Parte 1 Ejercicio 11 ***
//------------------------------------
//
// Calculo Formula

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    double x, y, f ;
    const double Factor = 1.531 , Pi = 3.141692 ;

    cout << "Resolución de F (x, y)" << endl
         << "**********************" << endl << endl
         << "Introduzca x: " ;
    cin  >> x ;

    cout << "Introduzca y: " ;
    cin  >> y ;

    f = sqrt( pow(Factor, (x + y)) + (( abs(exp(x) - exp(y)) * (sin(x) - tan(y))) / log10(y) * pow(Pi, x) )) ;

    cout << endl
         << "*****************" << endl
         << "F(" << x << ", " << y << ") = " << f << endl
         << "*****************" ;

    return 0;

}
