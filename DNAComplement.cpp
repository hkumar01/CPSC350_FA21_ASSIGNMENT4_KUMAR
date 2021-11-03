#include "DNAComplement.h"

DNAComplement::DNAComplement()
{

}

DNAComplement::~DNAComplement()
{
  delete DNAstack;
}

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
