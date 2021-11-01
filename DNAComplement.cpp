#include "DNAComplement.h"

DNAComplement::DNAComplement()
{

}

DNAComplement::~DNAComplement()
{
  delete DNAstack;
}

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
    else
    {
      throw runtime_error("Character was not a DNA complement.");
    }
  }
  return result;
}

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
