// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 4

#include "DNAComplement.h"

// constructor
DNAComplement::DNAComplement()
{

}

// destructor
DNAComplement::~DNAComplement()
{
  delete DNAstack;
}

// checkSequence() takes DNA sequence (string) as parameter
// function will return true if the DNA sequence contains invalid characters
bool DNAComplement::checkSequence(string line)
{
  bool check = false;
  // subtract 1 from string size to remove the newline character that is appended at end of line
  for (i = 0; i < line.size() - 1; ++i)
  {
    if (isalpha(line[i]))
    {
      if (line[i] == 'A' || line[i] == 'T' || line[i] == 'G' || line[i] == 'C')
      {
        continue;
      }
    }
    else
    {
      check = true;
    }
  }
  return check;
}

// printComplementDNA() will take DNA sequence (string) as parameter
// function will return complement of given DNA sequence
string DNAComplement::printComplementDNA(string line)
{
  string result;
  for (i = 0; i < line.size(); ++i)
  {
    if (line[i] == 'A')
    {
      result += "T";
    }
    else if (line[i] == 'T')
    {
      result += "A";
    }
    else if (line[i] == 'G')
    {
      result += "C";
    }
    else if (line[i] == 'C')
    {
      result += "G";
    }
  }
  return result;
}

// pushToStack() takes DNA sequence (string) as a parameter
// function will return reverse DNA complement (string)
string DNAComplement::pushToStack(string line)
{
  string answer;
  for (i = 0; i < line.size(); ++i)
  {
    DNAstack->push(line[i]);
  }

  while (!DNAstack->isEmpty())
  {
    answer += DNAstack->pop();
  }
  return answer;
}
