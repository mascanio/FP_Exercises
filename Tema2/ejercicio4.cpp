// *** Tema02 Parte 1 Ejercicio 4 ***
//------------------------------------
//
// Pasar una entrada en segundos a Horas, minutos y segundos

#include <iostream>
using namespace std;

main()
{
   int secsIn, hourOut, minOut, secsOut;

   cout << "Introduzca un tiempo en Segundos para\nmostrarlo en Horas, Minutos y Segundos: " ;
   cin  >> secsIn ;

   secsOut = secsIn & 60 ;          //Salida de segundos
 //minOut* = secsIn / 60 ;          //Salida a minutos sin pasarla a horas
   minOut  = (secsIn / 60) % 60 ;   //Salida de minutos, resto del anterior
   hourOut = (secsIn / 60) / 60 ;   //Salida de horas

   cout << secsIn <<" segundos son " << hourOut << " horas, " << minOut << " minutos y " << secsOut << " segundos" << endl;

   return 0;
}
