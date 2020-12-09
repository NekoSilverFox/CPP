#include "tasks.hpp"
#include <iostream>
#include <iterator>
#include <set>
#include "details.hpp"
#include "streamFunction.hpp"

void jianing::B5::task1(std::istream& istr, std::ostream& ostr)
{
  std::set<std::string> words = {sig::str_istr_iter(istr), sig::str_istr_iter()};
  sf::istreamNotEofAndFail(istr, "ERROR! Input stream anomalies. Reading failed in task1!\n");
  std::copy(words.begin(), words.end(), sig::str_ostr_iter(ostr, "\n"));
}
