#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include "DNAComplement.h"

class FileProcessor : public DNAComplement
{
  public:
    FileProcessor();
    ~FileProcessor();
    void processFile();
  private:
    string fileName;
    ifstream inputFile;
    ofstream outputFile;
    string complement;
    string lineText;
    string reverseComplement;
};

#endif
