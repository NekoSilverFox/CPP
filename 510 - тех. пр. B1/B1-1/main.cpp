#include "statement.hpp"
#include <stdexcept>

int main(int args, char* argv[])
{
  if ((args <= 1) || (args >= 5))
  {
    std::cerr << "ERROR! Wrong number of parameters!\n";
    return 1;
  }

  try
  {
    switch (*argv[1])
    {
      case '1':
        if (args == 3)
        {
          subject1(argv[2]);
        }
        else
        {
          throw std::invalid_argument("ERROR! Unrecognized parameter in case 1!");
        }
      break;

      case '2':
        if(args == 3)
        {
          subject2(argv[2]);
        }
        else
        {
          throw std::invalid_argument("ERROR! Unrecognized parameter in case 2!");
        }
      break;

      case '3':
        if (args == 2)
        {
          subject3();
        }
        else
        {
          throw std::invalid_argument("ERROR! Unrecognized parameter in case 3!");
        }
      break;

      case '4':
        if (args == 4)
        {
          subject4(argv[2], argv[3]);
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

  catch (std::exception const& ex)
  {
    std::cerr << ex.what() << "\n";
    return EXIT_FAILURE;
  }

  return 0;
}
