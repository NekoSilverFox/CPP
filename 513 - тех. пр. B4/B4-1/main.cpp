#include <iostream>
#include <algorithm>
#include <vector>
#include "dataStruct.hpp"

int main()
{
  std::vector<DataStruct> vec;

  try
  {
    while (std::cin.peek() != EOF)
    {
      if (std::cin.fail())
      {
        std::cerr << "ERROR! Wrong input";
        return 1;
      }

      vec.push_back(getDataFromLine());
    }

    if (std::any_of(vec.begin(), vec.end(), notInRange))
    {
      std::cerr << "ERROR! Value data not in range!";
      return 1;
    }

    std::sort(vec.begin(), vec.end(), lessThan);
    std::for_each(vec.begin(), vec.end(), outputData);
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what();
    return 1;
  }

  return 0;
}
