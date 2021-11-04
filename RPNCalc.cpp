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

  checkCalc = checkNumberOps(question);

  if (checkCalc)
  {
    returningValue = calculation(question);
  }
  else
  {
    throw runtime_error("Invalid calculation input.");
  }

  return returningValue;
}

bool RPNCalc::checkNumberOps(string calc)
{
  istringstream inSS(calc);
  string data;
  int numOperands = 0;
  int numOperators = 0;
  bool checkResult;

  while (inSS >> data)
  {
    const char* convert = data.c_str();
    char operand = '.';
    if (atoi(convert) != 0)
    {
      numOperands += 1;
    }
    else if (*convert == '+' || *convert == '-' || *convert == '*' || *convert == '/' || *convert == '%')
    {
      numOperators += 1;
    }
  }

  if (numOperands - numOperators == 1)
  {
    checkResult = true;
  }
  else
  {
    checkResult = false;
  }

  return checkResult;
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
     else if (*convert == '+' || *convert == '-' || *convert == '*' || *convert == '/' || *convert == '%')
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
       else if (operand == '%')
       {
         int num1 = stack->pop();
         int num2 = stack->pop();
         if (num1 > num2)
         {
           stack->push(num1 % num2);
         }
         else
         {
           stack->push(num2 % num1);
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
