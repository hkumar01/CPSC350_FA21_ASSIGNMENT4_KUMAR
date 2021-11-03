#include <iostream>
#include <string.h>
#include <exception>
#include "GenStack.h"
#include "DNAComplement.h"
#include "FileProcessor.h"
#include "RPNCalc.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    throw runtime_error("Missing command line arguments.");
  }
  else
  {
    if (strcmp(argv[1], "RPN") == 0)
    {
      cout << "RPN" << endl;
      RPNCalc *calculator = new RPNCalc();
      int print = calculator->prompt();
      cout << print << endl;
      delete calculator;
    }
    else if (strcmp(argv[1], "DNA") == 0)
    {
      cout << "DNA" << endl;
      FileProcessor *test = new FileProcessor();
      test->processFile();
      delete test;
    }
    else
    {
      throw runtime_error("Invalid arguments.");
    }
  }
  return 0;
}
