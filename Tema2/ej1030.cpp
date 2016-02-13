// Grupo01
// Miguel Ascanio Gómez y Javier Ortiz Iniesta
//
// *** Ejercicio extra ***
//------------------------

#include <iostream>
using namespace std;

#include <iomanip>

int main()
{
    int opcion = 1; //Declaraciones opcion de ejecucion
    bool opcionOK = false ; //Aux para opcion entre 0 y 3

    while(0 != opcion) //Al introducir 0 en ocion, fin
    {
        opcionOK = false ; //Volver a pedir opcion al acaba la anterior

        while(!opcionOK) //Pedir numero (opcion) entre 0 y 3 (mientras opcionOK false)
        {
            opcionOK = true ;

            cout << endl
                 << "*****************" << endl
                 << "SELECCIONE OPCIÓN" << endl
                 << "*****************" << endl << endl
                 << "1: Conversor de unidades" << endl
                 << "2: Tablas de multiplicar" << endl
                 << "3: Calculadora" << endl
                 << "0: Salir" << endl ;

            cin >> opcion ;

            if(3 < opcion)          //
                opcionOK = false ;  //
            if(0 > opcion)          // Opcion OK (false) si numero no esta entre las opciones 0 - 3
                opcionOK = false ;  //
        }

        if(1 == opcion) //***CONVERSOR***
        {
            double entrada = 1; //Declaraciones
            char unidad ;
            const double pulgadasCentimetros = 2.54 , //Factores de conversión
                         millasMetros = 1609.344 ,
                         fahrenheitCelsius = 1.8 , // F=(1.8 * C) + 32 ; suma añadida en la conversión
                         galonesLitro = 3.7854 ,
                         onzaGramos = 28.3495 ,
                         librasKilos = 0.4536 ;

             cout << endl
                  << "*********************" << endl
                  << "CONVERSOR DE UNIDADES" << endl
                  << "*********************" << endl << endl
                  << "Iintroduzca unidades para convertir según" << endl
                  << "el siguiente formato y tabla adjunta" << endl
                  << "   +Introducir un 0 para detener la ejecución" << endl << endl
                  << "------------- TABLA DE UNIDADES -------------" << endl
                  << "-----ENTRADA----------------------SALIDA-----" << endl
                  << " p -> pulgadas          a cm -> centímetros "   << endl
                  << " m -> millas            a  m -> metros"         << endl
                  << " f -> grados Fahrenheit a  c -> grados Celsius" << endl
                  << " g -> galones líquidos  a  l -> litros"         << endl
                  << " o -> onzas             a gr -> gramos"         << endl
                  << " l -> libras            a kg -> kilogramos"     << endl << endl
                  << "*********************************************" << endl
                  << "[valor a convertir]<espacio>[letra de unidad]" << endl
                  << "*********************************************" << endl ;

             while(0!=entrada)
             {
                cout << endl << "Introducir (0 para salir): " << endl ;
                cin >> entrada ; //Entrada [valor][unidad]

                if(0!=entrada) //si entrada = 0, omitir y salir del bucle conversor
                    cin	>> unidad ;

                if(unidad == 'p')
                    cout << "*******************" << endl
                         << entrada << unidad << " = " << entrada * pulgadasCentimetros << "cm" << endl
                         << "*******************";
                if(unidad == 'm')
                    cout << "*******************" << endl
                         << entrada << unidad << " = " << entrada * millasMetros << "m" << endl
                         << "*******************";
                if(unidad == 'f')
                    cout << "*******************" << endl
                         << entrada << unidad << " = " << entrada * fahrenheitCelsius + 32 << "c" << endl
                         << "*******************";
                if(unidad == 'g')
                    cout << "*******************" << endl
                         << entrada << unidad << " = "  << entrada * galonesLitro << "l" << endl
                         << "*******************";
                if(unidad == 'o')
                    cout << "*******************" << endl
                         << entrada << unidad << " = "  << entrada * onzaGramos << "gr" << endl
                         << "*******************";
                if(unidad == 'l')
                    cout << "*******************" << endl
                         << entrada << unidad << " = "  << entrada * librasKilos << "kg" << endl
                         << "*******************";
            }
        }

        if(2 == opcion) // ***TABLAS MULTIPLICAR***
        {
            int numero = 0, i = 0 ;
            bool rango = false; //Aux para numero entre 0 y 100

            cout << endl
                 << "********************************" << endl
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
        }

        if(3 == opcion) //***CALCULACORA***
        {
            double operando1 = 1, operando2, resultado;
            char operador;

            cout << endl
                 << "***********" << endl
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

                if(0 != operando1) //Si operando1 = 0, omitir y salir del bucle
                {
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

                            //Salida
                    cout << operando1 << " " << operador << " " << operando2 << " = " << resultado ;
                }
            }
        }
    }
    return 0;
}
