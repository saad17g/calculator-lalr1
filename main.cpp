#include "lexer.h"
#include "automate.h"
#include <iostream>

int main(void)
{
   cout << "----------------------------" << endl;
   cout << "To stop the program, type Q" << endl;
   cout << "----------------------------" << endl;
   cout << endl;
   string stream;
   do
   {
      cout << "Type a math formula: " << endl;

      cin >> stream;
      if (stream == "Q")
         break;
      Automate *automate = new Automate(stream);

      if (automate->calculate())
         cout << "The result is : " << automate->resultat << endl;
      else
         cout << "Error : a symbol was not recognized " << endl;
      cout << endl;
   } while (true);

   return 0;
}
