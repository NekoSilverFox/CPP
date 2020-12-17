#include "tasks.hpp"
#include <iostream>
#include <iterator>
#include <set>
#include "shapeDefine.hpp"
#include "streamFunction.hpp"
#include "errorHandling.hpp"

void jianing::B5::task1(std::istream& istr, std::ostream& ostr)
{
  std::set<std::string> words = {str_istr_iter(istr), str_istr_iter()};
  sf::istreamNotEofAndFail(istr, "ERROR! Input stream anomalies. Reading failed in task1!\n");
  std::copy(words.begin(), words.end(), str_ostr_iter(ostr, "\n"));
}
