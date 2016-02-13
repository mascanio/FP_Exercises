//Ejercicio 18

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int numero = 0, i = 0 ;

    cout << "********************************" << endl
         << "CALCULADOR TABLAS DE MULTIPLICAR" << endl
         << "********************************" << endl << endl
         << "Introduzca un número entre 1 y 100 (entero)" << endl
         << "para calcular tabla de multiplicación hasta 10" << endl;

    while(1)
    {
        cout << endl << "Introduzca número: " ; //Entrada
        cin >> numero ;
        cout << endl ;

        if(100 >= numero)
        {           //Si 1 <= numero <= 100 volver a pedir numero
            if(1 <= numero)
            {
                while(10 >= i) //Repetir hasta 10; salida multiplicando el numero hasta 10
                {
                    cout << setw(2) << i << "  X  " << setw(3) << numero << "   =  " << setw(4) << numero * i << endl ;
                    i++ ;
                }
                return 0;   //Fin de programa al llegar a 10
            }
        }
    }
}
