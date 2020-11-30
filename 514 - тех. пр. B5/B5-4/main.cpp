#include <exception>
#include <iostream>
#include <sstream>
#include "tasks.hpp"

int main(int args, char * argv[])
{
  try
  {
    if (args != 2)
    {
      std::cerr << "ERROR! Wrong number of parameters! It should be 2!\n";
      return 1;
    }
   
    switch (std::stoi(argv[1]))
    {
    case 1:
    {
      jianing::B5::task1(std::cin, std::cout);
      break;
    }
    case 2:
    {
      jianing::B5::task2(std::cin, std::cout);
      break;
    }
    default:
    {
      std::cerr << "ERROR! Wrong number of parameters! It should be [1] or [2]!\n";
      return 1;
    }
    }
  }
  catch (const std::exception &exc)
  {
    std::cerr << exc.what() << "\n";
    return 1;
  }

  return 0;
}
