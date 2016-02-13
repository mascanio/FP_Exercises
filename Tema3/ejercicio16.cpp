#include <iostream>
using namespace std;

#include <fstream>

int main()
{
   ifstream lectura;
   ofstream escritura;

   const int Centinela = 0;

   int entrada = 1;

   lectura.open("input.txt");
   escritura.open("output.txt");

   if (lectura.is_open() && escritura.is_open())
   {
      lectura >> entrada;

      while (entrada != Centinela) //Leer de archivo hasta centinela
      {
         if (entrada > 0)
         {
            while (entrada != 0) //Realizar division/módulo hasta que sea 0
            {
               escritura << entrada % 10; //Escribir mientras se ejecuta el bucle
               entrada /= 10;
            }
            escritura << endl;
         }
         lectura >> entrada;
      }
   }

   escritura.close();
   lectura.close();
   return 0;
}
