#include <iostream>
#include "statement.hpp"

using namespace std;

int main(int argv, char* args[])
{
  if ((argv <= 1) || (argv >= 5))
  {
    std::cerr << "Wrong number of parameters\n";
    return 1;
  }

  switch (*args[1])
  {
    case '1':
      if (1)
      {

      }
  }
  return 0;
}
