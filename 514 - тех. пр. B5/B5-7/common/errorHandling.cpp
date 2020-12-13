#include "errorHandling.hpp"
#include <iostream>

void jianing::printError(std::ostream& oerr)
{
  oerr << "[ERROR MESSAGE] " << errInfoCode.first << "\n"
       << "[ERROR CODE] " << errInfoCode.second << "\n";
}

void jianing::cleanErrInfo()
{
  errInfoCode.first = "No Error";
  errInfoCode.second = 0;
}
