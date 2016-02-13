// Grupo01
// Miguel Ascanio Gómez y Javier Ortiz Iniesta
//
// *** Tema02 Parte 1 Ejercicio 12 ***
//------------------------------------
//
// Calculo cuota mensual de prestamos

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    double cuota, capital, ratio ; //Declaraciones
    int plazo ;

    cout << "*****************************" << endl
         << "CÁLCULO DE CUOTA DE PRÉSTAMOS" << endl
         << "*****************************" << endl << endl
         << "Itroduzca los datos solicitados para calcular la cutoa mensual del préstamo:" << endl << endl

        //Entrada de datos
         << "-----------------------------------------------" << endl
         << "Introduzca el CAPITAL PRESTADO: " ;
    cin  >> capital ;

    cout << "Introduzca el INTERÉS ANUAL: " ;
    cin  >> ratio ;

	ratio /= 12;

	cout << "Introduzca el PLAZO DEL PRÉSTAMO (en años): " ;
    cin  >> plazo ;

        //Formula calculo de cuota mensual
    cuota = (capital * ratio  )  / (100 * (1 - pow(1 + ratio / 100, -plazo * 12) )) ;

        //Salida
    cout << "-----------------------------------------------" << endl << endl
         << "Capital prestado: \t\t"  << capital << endl
         << "Interés mensual: \t\t"   << ratio  << " meses" << endl
         << "Plazo del présatmo \t\t" << plazo * 12 << " meses" << endl << endl

         << "****************************************" << endl
         << "Cuota mensual: \t\t\t" << cuota << endl
         << "****************************************" << endl
         << "Total a pagar: \t\t\t" << cuota * plazo * 12 << endl
         << "****************************************" ;

    return 0;

}
