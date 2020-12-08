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

    void streamNotEof(std::istream& istr, const char* err_msg);
    void streamNotEofAndFail(std::istream& istr, const char* err_msg);
    void streamBad(std::istream& istr, const char* err_msg);
  }
}

#endif // STREAMFUNCTION_HPP
