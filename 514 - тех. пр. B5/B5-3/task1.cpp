#include "tasks.hpp"
#include <iostream>
#include <iterator>
#include <set>
#include "details.hpp"

void jianing::B5::task1(std::istream& istr, std::ostream& ostr)
{
  std::set<std::string> words = {sig::str_istr_iter(istr), sig::str_istr_iter()};

  if (!istr.eof() && istr.fail())
  {
    throw std::invalid_argument("[invalid_argument] ERROR! Input stream anomalies. Reading failed in task1!\n");
  }

  std::copy(words.begin(), words.end(), sig::str_ostr_iter(ostr, "\n"));
}
