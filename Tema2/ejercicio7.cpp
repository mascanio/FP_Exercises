// Grupo01
// Miguel Ascanio Gómez y Javier Ortiz Iniesta
//
// *** Tema02 Parte 1 Ejercicio 7 ***
//------------------------------------
//
// Expresion

#include <iostream>
using namespace std;

int main ()
{
    int x = 12, y = 3; //Declaraciones e inicializaciones
    double sigma = 2.1836, lambda = 1.11695, alfa = 328.67, f ;

    f = 3*( (x + sigma * y) / (x*x - y*y) ) - lambda *(alfa - 13.7) ;

    cout << "El valor de  3( (x + sigma * y) / (x*x - y*y) ) - lambda *(alfa - 13.7) , siendo " <<endl
         << "x \t=\t"      << x << endl
         << "y \t=\t"      << y << endl
         << "sigma   = \t"  << sigma << endl
         << "lambda  = \t" << lambda << endl
         << "alfa\t=\t"   << alfa << endl << endl
         << "*************************" << endl
         << "es:\t\t"    << f << endl
         << "*************************" ;

    return 0;
}
