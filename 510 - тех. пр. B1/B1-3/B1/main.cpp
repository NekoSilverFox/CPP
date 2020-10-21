#include <iostream>
#include <fstream>
#include <stdexcept>
#include "allSubjects.hpp"

int main(int args, char* argv[])
{
  if ((args < 2) || (args > 4))
  {
    std::cerr << "ERROR! The quantity of arguments of the program should between [2, 4]!\n";
    return 1;
  }

  try
  {
    switch (*argv[1])
    {
      case '1':
        if (args == 3)
        {
          jianing::subject1(argv[2]);
        }
        else
        {
          throw std::invalid_argument("ERROR! Unrecognized parameter in case 1!");
        }
      break;

      case '2':
        if(args == 3)
        {
          jianing::subject2(argv[2]);
        }
        else
        {
          throw std::invalid_argument("ERROR! Unrecognized parameter in case 2!");
        }
      break;

      case '3':
        if (args == 2)
        {
          jianing::subject3();
        }
        else
        {
          throw std::invalid_argument("ERROR! Unrecognized parameter in case 3!");
        }
      break;

      case '4':
        if (args == 4)
        {
          jianing::subject4(argv[2], argv[3]);
        }
        else
        {
          throw std::invalid_argument("ERROR! Unrecognized parameter in case 4!");
        }
      break;

    default:
      throw std::invalid_argument("ERROR! Unrecognized parameter in case default!");
      break;
    }
  }
  catch (const std::domain_error& exc)
  {
    std::cerr << "Catch error [domain_error] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (const std::invalid_argument& exc)
  {
    std::cerr << "Catch error [invalid_argument] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (const std::out_of_range& exc)
  {
    std::cerr << "Catch error [out_of_range] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (const std::ios_base::failure& exc)
  {
    std::cerr << "Catch error [failure] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (...)
  {
    std::cerr << "An unrecognized exception occurred in the program!\n";
    return 1;
  }

  return 0;
}
