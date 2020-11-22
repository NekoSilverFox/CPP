#include <exception>
#include <iostream>
#include <sstream>

void task1();
void task2();

int main(int args, char * argv[])
{
  try
  {
    if (args != 2)
    {
      std::cerr << "Wrong number of parameters for task! \n" << std::endl;
      return 1;
    }
   
    switch (std::stoi(argv[1]))
    {
    case 1:
    {
      task1();
      break;
    }
    case 2:
    {
      task2();
      break;
    }
    default:
    {
      std::cerr << "wrong task number! \n" << std::endl;
      return 1;
    }
    }
  }
  catch (const std::exception &excep)
  {
    std::cerr << excep.what();
    return 1;
  }

  return 0;
}