#include "task.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include "dataStruct.hpp"

void jianing::B4::task(std::istream& istr, std::ostream& ostr)
{
  std::vector<DataStruct> vec = {sig::ds_istr_iter(istr), sig::ds_istr_iter()};

  if (!istr.eof())
  {
    throw std::invalid_argument("ERROR! Invalid input!\n");
  }

  std::sort(vec.begin(), vec.end(), Compare());
  std::copy(vec.begin(), vec.end(), sig::ds_ostr_iter(ostr, "\n"));
}
