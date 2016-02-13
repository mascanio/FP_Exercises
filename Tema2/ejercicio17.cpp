//Ejercicio 17

#include <iostream>
using namespace std;

int main()
{
	double entrada = 1; //Declaraciones
    char unidad ;
    const double pulgadasCentimetros = 2.54 , //Factores de conversión
                 millasMetros = 1609.344 ,
                 fahrenheitCelsius = 1.8 , // F=(1.8 * C) + 32 ; suma añadida en la conversión
                 galonesLitro = 3.7854 ,
                 onzaGramos = 28.3495 ,
                 librasKilos = 0.4536 ;

	 cout << "*********************" << endl
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
        cout << endl << "Introducir: " << endl ;
        cin >> entrada ; //Entrada [valor][unidad]

        if(0!=entrada) //si entrada = 0, omitir y salir del bucle (finalizar)
            cin	>> unidad ;

        if(unidad == 'p')
            cout << "*******************" << endl
                 << entrada << unidad << " = " << entrada * pulgadasCentimetros << " cm" << endl
                 << "*******************";
        if(unidad == 'm')
            cout << "*******************" << endl
                 << entrada << unidad << " = " << entrada * millasMetros << " m" << endl
                 << "*******************";
        if(unidad == 'f')
            cout << "*******************" << endl
                 << entrada << unidad << " = " << entrada * fahrenheitCelsius + 32 << " c" << endl
                 << "*******************";
        if(unidad == 'g')
            cout << "*******************" << endl
                 << entrada << unidad << " = "  << entrada * galonesLitro << " l" << endl
                 << "*******************";
        if(unidad == 'o')
            cout << "*******************" << endl
                 << entrada << unidad << " = "  << entrada * onzaGramos << " gr" << endl
                 << "*******************";
        if(unidad == 'l')
            cout << "*******************" << endl
                 << entrada << unidad << " = "  << entrada * librasKilos << " kg" << endl
                 << "*******************";
    }
	return 0;
}
