#include "allSubjects.hpp"
#include <iostream>
#include <vector>
#include <forward_list>
#include "statement.hpp"

void jianing::subject1(const char* sort_type)
{
  std::vector<int> vec_first;
  pushElements<int>(vec_first);
  auto comp_method = defineSortType<int>(sort_type);

  std::vector<int> vec_sec = vec_first;
  std::forward_list<int> list(vec_first.begin(), vec_first.end());

  bubbleSort<bracketAccess, std::vector<int> >(vec_first, comp_method);
  printData<std::vector<int> >(vec_first);

  bubbleSort<atAccess, std::vector<int> >(vec_sec, comp_method);
  printData<std::vector<int> >(vec_sec);

  bubbleSort<iteratorAccess, std::forward_list<int> >(list, comp_method);
  printData<std::forward_list<int> >(list);
}
