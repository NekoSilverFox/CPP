#include "allSubjects.hpp"
#include <iostream>
#include <vector>
#include <forward_list>
#include "statement.hpp"

void jianing::subject1(const char* sort_type)
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
  if (std::cin.bad())
  {
    throw std::ios_base::failure("ERROR! A serious exception occurred in the import stream (in subject1)!\n");
  }
  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::invalid_argument("ERROR! Data import is abnormal!\n");
  }

  /*
  ** Determine sort type
  */
  auto comp_method = jianing::defineSortType<int>(sort_type);

  std::vector<int> vec_sec = vec_first;
  std::forward_list<int> list(vec_first.begin(), vec_first.end());

  bubbleSort<bracketAccess, std::vector<int> >(vec_first, comp_method);
  printData<std::vector<int> >(vec_first);

  bubbleSort<atAccess, std::vector<int> >(vec_sec, comp_method);
  printData<std::vector<int> >(vec_sec);

  bubbleSort<iteratorAccess, std::forward_list<int> >(list, comp_method);
  printData<std::forward_list<int> >(list);
}
