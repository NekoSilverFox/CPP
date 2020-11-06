#ifndef INFO_HPP
#define INFO_HPP
#include <iostream>

namespace info
{
  static const char* ERR_EMPTY = "<EMPTY>\n";
  static const char* ERR_INVALID_COM = "<INVALID COMMAND>\n";
  static const char* ERR_INVALIN_STEP = "<INVALID STEP>\n";
  static const char* MARK_CURRENT = "current";
}

inline void printAllInfo()
{
  std::cout << info::ERR_EMPTY << "\n"
            << info::MARK_CURRENT << "\n"
            << info::ERR_INVALID_COM << "\n"
            << info::ERR_INVALIN_STEP << "\n";
}
#endif // INFO_HPP
