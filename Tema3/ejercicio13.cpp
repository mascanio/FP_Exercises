#include <iostream>
using namespace std;

int main()
{
   int entrada = 1;

   bool ejecutar = true;

   while (ejecutar)
   {
      cout <<endl << "Introduzca número para hallar su invertido (<= 0 para finalizar): " ;
      cin >> entrada;

      if(entrada <= 0)
         ejecutar = false;
      else
         cout << "El invertido de " << entrada << " es: ";

      while (entrada > 0) 
      {
         cout << entrada % 10;
         entrada /= 10;
      }
   }
   return 0;
}
