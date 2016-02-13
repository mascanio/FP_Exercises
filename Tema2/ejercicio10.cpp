// Grupo01
// Miguel Ascanio Gómez y Javier Ortiz Iniesta
//
// *** Tema02 Parte 1 Ejercicio 9 ***
//------------------------------------
//
// Calculo area del triangulo

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    cout << "*** CALCULO DE AREAS DE TRIANGULOS ***" << endl << endl
         << "Introduzca los datos solicitados para calcular" << endl
         << "el area de un triangulo a partir de sus lados y el angulo comprendido." << endl
         << "----------------------------------------------------------------------" << endl ;

        const double Pi = 3.141592 ;    //Declaración Pi y variables
        double lado1, lado2, angulo, radianes ;
		const double RadianesPorGrado = Pi / 180 ;

    //Entrada datos
        cout << "Introduzca lado 1: " ;
        cin >> lado1 ;

        cout << "Introduzca lado 2: "  ;
        cin >> lado2 ;

        cout << "Introduzca valor del angulo comprendido entre los lados 1 y 2: " ;
        cin >> angulo ;

		radianes = RadianesPorGrado * angulo;

    //Salida (formula de area incluida)
        cout << endl
             << "************************************" << endl
             << "El area del triangulo es: " << 0.5 * lado1 * lado2 * sin(radianes) << "u^2" << endl
             << "************************************" ;

    return 0;

}
