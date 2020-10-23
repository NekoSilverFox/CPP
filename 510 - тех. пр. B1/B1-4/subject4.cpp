#include "allSubjects.hpp"
#include "statement.hpp"

void jianing::subject4(const char* sort_type, const char* array_size)
{
  int size = atoi(array_size);

  if (size == 0)
  {
    throw std::invalid_argument("ERROR! Wrong size of this array, need greater than zero!\n");
  }

  std::vector<double> vec(size);
  initArray(&vec[0], size);
  auto comp_method = defineSortType<double>(sort_type);

  printData<std::vector<double> >(vec);
  bubbleSort<bracketAccess, std::vector<double> >(vec, comp_method);
  printData<std::vector<double> >(vec);
}
