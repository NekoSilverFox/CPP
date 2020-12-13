#ifndef ERRORHANDLING_HPP
#define ERRORHANDLING_HPP
#include <iostream>

namespace jianing
{
  /*
   * first - Error info
   * second - Error code
   */
  using err_t = std::pair<std::string, int>;
  static err_t errInfoCode = std::make_pair("No Error", 0);

  void printError(std::ostream& oerr);
  void cleanErrInfo();
}

#endif // ERRORHANDLING_HPP
