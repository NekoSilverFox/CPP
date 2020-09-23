#include <iostream>
#include <cstring>
#include <vector>
#include <forward_list>
#include "statement.hpp"

void subject1(const char* sort_type)
{
  std::vector<int> vec_first;
  int num = 0;

  /*
  ** input number into the vector
  */
  while (std::cin >> num)
  {
    vec_first.push_back(num);
  }

  /*
  ** check
  */
  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::invalid_argument("Data import is abnormal!\n");
  }

  /*
  ** Determine sort type
  */
  bool (*comp_method)(int&, int&) = nullptr;

  if (!std::strcmp(sort_type, "ascending"))
  {
    comp_method = jianing::greater;
  }
  else if (!std::strcmp(sort_type, "descending"))
  {
    comp_method = jianing::less;
  }
  else
  {
    throw std::invalid_argument("Unknown sort type!\n");
  }

  std::vector<int> vec_sec = vec_first;
  std::forward_list<int> list(vec_first.begin(), vec_first.end());

  jianing::bubbleSort<jianing::bracketAccess, std::vector<int>>(vec_first, comp_method);
  jianing::printData<std::vector<int>>(vec_first);

  jianing::bubbleSort<jianing::atAccess, std::vector<int>>(vec_sec, comp_method);
  jianing::printData<std::vector<int>>(vec_sec);

  jianing::bubbleSort<jianing::iteratorAccess, std::forward_list<int>>(list, comp_method);
  jianing::printData<std::forward_list<int>>(list);
}
