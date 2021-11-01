#include "RPNCalc.h"

RPNCalc::RPNCalc()
{

}

RPNCalc::~RPNCalc()
{

}

void RPNCalc::prompt()
{
  cout << "Enter a calulation in postfix notation." << endl;

  string question;
  getline(cin, question);

  calculation(question);
}

int RPNCalc::calculation(string calc)
{
   istringstream inSS(calc);
   string data;

   while (inSS >> data)
   {
     const char* convert = data.c_str();
     if (atoi(convert) == 0)
     {
       continue;
     }
     else
     {
       int element = atoi(convert);
       stack->push(element);
       cout << "added element." << endl;
     }
   }
   return 0;
}
