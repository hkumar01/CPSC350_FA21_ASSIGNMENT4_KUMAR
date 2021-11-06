// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 4

//RPNCalc class takes math operations in post-fix notation 

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
