#include <iostream>
using namespace std;
#include <cctype>
int main ()
{
   //system ("chcp 1252");

   char letra;
   int contadorLetra, contadorBlanco, contadorDigitos;
   bool encontrado, fin = false;

   while (!fin)
   {
      contadorLetra = 0;
      contadorBlanco = 0;
      contadorDigitos = 0;
      encontrado = false;

      cout << "Introduzca cadena (finalizado en punto): ";

      cin.get (letra) ;
      if (letra == '.')
         fin = true;

      while (letra != '.' && !encontrado)
      {
         if (letra == '(' )
         {
            encontrado = true;

            while(letra != ')' && letra != '.')
            {
               if (isalpha (letra))
                  contadorLetra++;
               else if (isdigit (letra))
                  contadorDigitos++;
               else if (letra == ' ')
                  contadorBlanco++;

               cin.get (letra) ;
            }
         }
         else
            cin.get (letra) ;
      }

      cout << "Letras: " << contadorLetra << endl
         << "Dígito: " << contadorDigitos << endl
         << "Blancos: " << contadorBlanco << endl;

      cin.sync();
   }
   return 0;
}
