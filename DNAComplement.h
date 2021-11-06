// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 4

// handle creating DNA complement and reverse comoplement 

#ifndef DNACOMPLEMENT_H
#define DNACOMPLEMENT_H

#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "GenStack.h"

class DNAComplement
{
  public:
    DNAComplement();
    ~DNAComplement();
    bool checkSequence(string line);
    string printComplementDNA(string line);
    string pushToStack(string line);
  private:
    int i;
    GenStack<char> *DNAstack = new GenStack<char>();
};

#endif
