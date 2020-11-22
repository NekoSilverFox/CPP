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

  if (std::any_of(vec.begin(), vec.end(), notInRange))
  {
    throw std::invalid_argument("ERROR! Value data does not in range. Number should between [-5, +5]!\n");
  }

  std::sort(vec.begin(), vec.end(), Compare());
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<DataStruct>(ostr));
}

#endif // TASK_HPP
