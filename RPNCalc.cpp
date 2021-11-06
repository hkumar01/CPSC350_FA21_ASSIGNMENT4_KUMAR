// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 4

#include "RPNCalc.h"

// RPNCalc() is constructor
RPNCalc::RPNCalc()
{

}

// ~RPNCalc() is destructor
RPNCalc::~RPNCalc()
{

}

// prompt() is called upon RPNCalc program start-up
// prompts user for post-fix notation calculation
// checks if calculation is valid, if not throws runtime_error
// returns answer to calculation as an integer
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

// checkNumberOps() takes a calculation as a string
// counts number of operands and operators
// valid equation has one less operator than number of operands
// returns true or false, depending on if calculation is valid
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

// calculation() takes a calculation as a string
// compute the calculation and return the result as an integer
// if an invalid character is encountered, program will throw a runtime_error 
int RPNCalc::calculation(string calc)
{
   istringstream inSS(calc);
   string data;
   int answer;

   while (inSS >> data)
   {
     const char* convert = data.c_str();
     char operand = '.';
     // if atoi() returns 1 then convert the integer and push to stack
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
}
