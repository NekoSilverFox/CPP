#ifndef TASK_HPP
#define TASK_HPP
#include <algorithm>
#include <iterator>
#include <vector>
#include "dataStruct.hpp"

namespace jianing
{
  namespace B4
  {
    void task(std::istream& istr, std::ostream& ostr);
  }
}

void jianing::B4::task(std::istream& istr, std::ostream& ostr)
{
  std::vector<DataStruct> vec = {std::istream_iterator<DataStruct>(istr), std::istream_iterator<DataStruct>()};

  if (!istr.eof())
  {
    throw std::invalid_argument("ERROR! Invalid input!\n");
  }

  std::sort(vec.begin(), vec.end(), Compare());
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<DataStruct>(ostr, "\n"));
}

#endif // TASK_HPP
