#include "FileProcessor.h"

FileProcessor::FileProcessor()
{

}

FileProcessor::~FileProcessor()
{

}

void FileProcessor::processFile()
{
  cout << "Enter a DNA text file." << endl;
  cin >> fileName;

  inputFile.open(fileName);
  if (!inputFile.is_open())
  {
    throw runtime_error("Cannot open file.");
  }

  outputFile.open("dnaoutput.txt");

  while (!inputFile.eof())
  {
    getline(inputFile, lineText);

    cout << "Original:" << endl;
    outputFile << "Original:" << endl;

    cout << lineText << endl;
    outputFile << lineText << endl;

    complement = printComplementDNA(lineText);

    cout << "Complement:" << endl;
    outputFile << "Complement:" << endl;

    cout << complement << endl;
    outputFile << complement << endl;

    reverseComplement = pushToStack(complement);

    cout << "Reverse Complement:" << endl;
    outputFile << "Reverse Complement:" << endl;

    cout << reverseComplement << endl;
    outputFile << reverseComplement << endl;
  }
  inputFile.close();
  outputFile.close();
}
