#include <iostream>
#include "task.hpp"

int main()
{
  try
  {
    jianing::B4::task(std::cin, std::cout);
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
  catch (...)
  {
    std::cerr << "An unrecognized exception occurred in the program!\n";
    return 2;
  }

  return 0;
}
