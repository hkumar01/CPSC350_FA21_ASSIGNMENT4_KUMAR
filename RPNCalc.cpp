#include "RPNCalc.h"

RPNCalc::RPNCalc()
{

}

RPNCalc::~RPNCalc()
{

}

int RPNCalc::prompt()
{
  int returningValue;
  cout << "Enter a calulation in postfix notation." << endl;

  string question;
  getline(cin, question);

  returningValue = calculation(question);
  return returningValue;
}

int RPNCalc::calculation(string calc)
{
   istringstream inSS(calc);
   string data;
   int answer;

   while (inSS >> data)
   {
     const char* convert = data.c_str();
     char operand = '.';
     if (atoi(convert) != 0)
     {
       int element = atoi(convert);
       stack->push(element);
     }
     else if (*convert == '+' || *convert == '-' || *convert == '*' || *convert == '/')
     {
       operand = *convert;
       if (operand == '+')
       {
         stack->push((stack->pop() + stack->pop()));
       }
       else if (operand == '-')
       {
         int num1 = stack->pop();
         int num2 = stack->pop();
         if (num1 > num2)
         {
           stack->push(num1 - num2);
         }
         else
         {
           stack->push(num2 - num1);
         }
       }
       else if (operand == '*')
       {
         stack->push((stack->pop() * stack->pop()));
       }
       else if (operand == '/')
       {
         int num1 = stack->pop();
         int num2 = stack->pop();
         if (num1 > num2)
         {
           stack->push(num1 / num2);
         }
         else
         {
           stack->push(num2 / num1);
         }
       }
     }
     else
     {
       throw runtime_error("Invalid operand or operator. Exiting");
     }
   }
   return stack->pop();
   return 0;
}
