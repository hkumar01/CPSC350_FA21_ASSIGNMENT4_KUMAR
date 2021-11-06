// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 4

#include "FileProcessor.h"

// constructor
FileProcessor::FileProcessor()
{

}

// destructor
FileProcessor::~FileProcessor()
{

}

// processFile() will prompt user for DNA text file
// will check if DNA sequences from text file are valid, if not throw runtime_error
// Original DNA sequence, complement sequence, and reverse complement are printed to output text file
void FileProcessor::processFile()
{
  cout << "Enter a DNA text file." << endl;
  cin >> fileName;

  inputFile.open(fileName);
  if (!inputFile.is_open())
  {
    throw runtime_error("Cannot open file. Exiting.");
  }

  outputFile.open("dnaoutput.txt");

  while (!inputFile.eof())
  {
    getline(inputFile, lineText);

// when file reaches a newline (empty string), exit from loop
    if (lineText.empty())
    {
      break;
    }

    outputFile << "Original:" << endl;
    outputFile << lineText << endl;

  // if DNA sequence is invalid then throw runtime_error
    if (checkSequence(lineText) == true)
    {
      throw runtime_error("Invalid DNA character found. Exiting.");
    }

    else
    {
      complement = printComplementDNA(lineText);

      outputFile << "Complement:" << endl;
      outputFile << complement << endl;

      reverseComplement = pushToStack(complement);

      outputFile << "Reverse Complement:" << endl;
      outputFile << reverseComplement << endl;
    }
  }
  inputFile.close();
  outputFile.close();
}
