//Ejercicio 19

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double operando1 = 1, operando2, resultado;
    char operador;

    cout << "***********" << endl
         << "CALCULADORA" << endl
         << "***********" << endl << endl
         << "Intruduzca un número (real) seguido de un operador (+, -, *, /)" << endl
         << "y otro número real para calcular la operación" << endl
         << "   +Detener ejecución con un 0 en el primer operador" << endl
         << "----------------------------------------------------" ;

    while(0 != operando1)
    {
        cout << endl << endl << "<Operando> <Operador> <Operando> " ; //Entrada
        cin >> operando1;

        if(0 == operando1) //Si operando1 = 0; detener
            return 0;

        cin >> operador >> operando2 ;
        cout << endl ;

            // Analizar operador y asignar resultado
        if('+' == operador) //Suma
            resultado = operando1 + operando2 ;
        if('-' == operador) //Resta
            resultado = operando1 - operando2 ;
        if('*' == operador) //Producto
            resultado = operando1 * operando2 ;
        if('/' == operador) //Resta
            resultado = operando1 / operando2 ;

        cout << operando1 << " " << operador << " " << operando2 << " = " << resultado ;
    }
}
