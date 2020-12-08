#include "task.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include "dataStruct.hpp"
#include "streamFunction.hpp"

void jianing::B4::task(std::istream& istr, std::ostream& ostr)
{
  std::vector<DataStruct> vec = {sig::ds_istr_iter(istr), sig::ds_istr_iter()};
  sf::istreamNotEof(istr, "ERROR! Invalid input!\n");
  std::sort(vec.begin(), vec.end(), Compare());
  std::copy(vec.begin(), vec.end(), sig::ds_ostr_iter(ostr, "\n"));
}
