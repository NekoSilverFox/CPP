#include "errorHandling.hpp"
#include <iostream>

void jianing::printError(std::ostream& oerr)
{
  if (errInfoCode.second != 0)
  {
    oerr << "[ERROR MESSAGE] " << errInfoCode.first << "\n"
         << "[ERROR    CODE] " << errInfoCode.second << "\n";
  }
}

void jianing::throwError()
{
  if (errInfoCode.second != 0)
  {
    throw std::invalid_argument(errInfoCode.first.c_str());
  }
}

void jianing::cleanErrInfo()
{
  errInfoCode.first = "No Error";
  errInfoCode.second = 0;
}
