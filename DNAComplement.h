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
