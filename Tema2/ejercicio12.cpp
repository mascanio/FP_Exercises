// Grupo01
// Miguel Ascanio G�mez y Javier Ortiz Iniesta
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
         << "C�LCULO DE CUOTA DE PR�STAMOS" << endl
         << "*****************************" << endl << endl
         << "Itroduzca los datos solicitados para calcular la cutoa mensual del pr�stamo:" << endl << endl

        //Entrada de datos
         << "-----------------------------------------------" << endl
         << "Introduzca el CAPITAL PRESTADO: " ;
    cin  >> capital ;

    cout << "Introduzca el INTER�S ANUAL: " ;
    cin  >> ratio ;

	ratio /= 12;

	cout << "Introduzca el PLAZO DEL PR�STAMO (en a�os): " ;
    cin  >> plazo ;

        //Formula calculo de cuota mensual
    cuota = (capital * ratio  )  / (100 * (1 - pow(1 + ratio / 100, -plazo * 12) )) ;

        //Salida
    cout << "-----------------------------------------------" << endl << endl
         << "Capital prestado: \t\t"  << capital << endl
         << "Inter�s mensual: \t\t"   << ratio  << " meses" << endl
         << "Plazo del pr�satmo \t\t" << plazo * 12 << " meses" << endl << endl

         << "****************************************" << endl
         << "Cuota mensual: \t\t\t" << cuota << endl
         << "****************************************" << endl
         << "Total a pagar: \t\t\t" << cuota * plazo * 12 << endl
         << "****************************************" ;

    return 0;

}
