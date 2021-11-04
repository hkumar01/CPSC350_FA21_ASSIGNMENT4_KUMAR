#ifndef RPNCALC_H
#define RPNCALC_H

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "GenStack.h"

 using namespace std;

 class RPNCalc
 {
  public:
    RPNCalc();
    ~RPNCalc();

    int prompt();
    int calculation(string calc);
    bool checkNumberOps(string calc);
  private:
    GenStack<int> *stack = new GenStack<int>();
    bool checkCalc;
 };

 #endif
