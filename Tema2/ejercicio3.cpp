// *** Tema02 Parte 1 Ejercicio 3 ***
//------------------------------------
//
// Conversor de Fahrenheit a Celsius
//ºC = 5 / 9 x (ºF - 32)

#include <iostream>

using namespace std;

main()
{
    double celsius, fahrenheit; //Declaracion

    cout << "*** Conversor de grados Fahrenheit a Celsius ***\n\n"
         << "Introduzca valor de Fahrenheit para convertir: " ;
    cin  >> fahrenheit ;         //Leer Fahrenheit de consola

    celsius = 5 * (fahrenheit - 32) / 9; //Formula de conversion

    cout << fahrenheit << " grados fahrenheit son " << celsius << " grados celsius" << endl; //Mostrar resultado

    return 0;
}
