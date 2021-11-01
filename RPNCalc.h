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

    void prompt();
    int calculation(string calc);
  private:
    GenStack<int> *stack = new GenStack<int>();
 };

 #endif