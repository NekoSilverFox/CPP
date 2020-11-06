#include <iostream>
#include <string>
#include "info.hpp"
#include "tasks.hpp"
#include "info.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << info::ERR_INVALID_COM;
      return 1;
    }

    switch (std::stoi(argv[1]))
    {
      case 1:
      {
        task1();
        return 0;
      }

      case 2:
      {
        task2();
        return 0;
      }

      default:
      {
        std::cerr << info::ERR_INVALID_COM;
        return 1;
      }
    }
  }

  catch (const std::exception & err)
  {
    std::cerr << err.what() << std::endl;
    return 1;
  }

  return 0;
}
