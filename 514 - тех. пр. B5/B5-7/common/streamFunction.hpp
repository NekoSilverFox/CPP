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

    void istreamNotEof(std::istream& istr, const char* err_msg);
    void istreamNotEofAndFail(std::istream& istr, const char* err_msg);
    void istreamBad(std::istream& istr, const char* err_msg);
  }
}

#endif // STREAMFUNCTION_HPP
