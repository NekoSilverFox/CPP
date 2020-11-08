#include <iostream>
#include <string>
#include "info.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "ERROR! Please enter the parameters [number of the task]!\n";
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
        std::cerr << "ERROR! Unrecognizable parameters! Please enter number [1] or [2]\n";
        return 1;
      }
    }
  }
  catch (const std::invalid_argument& exc)
  {
    std::cerr << "Catch error [invalid_argument] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (const std::runtime_error& exc)
  {
    std::cerr << "Catch error [runtime_error] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (const std::out_of_range& exc)
  {
    std::cerr << "Catch error [out_of_range] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (...)
  {
    std::cerr << "An unrecognized exception occurred in the program!\n";
    return 2;
  }

  return 0;
}
