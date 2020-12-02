#ifndef STREAMFUNCTION_HPP
#define STREAMFUNCTION_HPP
#include <iostream>

namespace jianing
{
  /*
   * sf - Stream function
   */
  namespace sf
  {
    /*
     * remove space, Tab, empty char in the input stream
     */
    std::istream& rmw(std::istream& istr);
  }
}

#endif // STREAMFUNCTION_HPP
