//Ejercicio 18

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int numero = 0, i = 0 ;
    bool rango = false;

    cout << "********************************" << endl
         << "CALCULADOR TABLAS DE MULTIPLICAR" << endl
         << "********************************" << endl << endl ;

    while(!rango) //Pedir numero entre 0 y 100 (mientras rango false)
    {
        rango = true ;

        cout << "Introduzca un número entre 1 y 100 (entero)" << endl
             << "para calcular tabla de multiplicación hasta 10" << endl;
        cin >> numero ;

        if(100 <= numero)       //
            rango = false ;     //
        if(0 >= numero)         // Rango (false) si numero no esta entre 0 y 100
            rango = false ;     //
    }


    while(10 >= i) //Repetir hasta 10; salida multiplicando el numero hasta 10
    {
        cout << setw(2) << i << "  X  " << setw(3) << numero << "   =  " << setw(4) << numero * i << endl ;
        i++ ;
    }

    return 0 ;
}
