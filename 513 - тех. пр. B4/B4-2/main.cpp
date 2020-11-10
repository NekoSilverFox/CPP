#include <iostream>
#include <algorithm>
#include <vector>
#include "dataStruct.hpp"
#include "checkStream.hpp"

int main()
{
  std::vector<DataStruct> vec;

  try
  {
    while (std::cin.peek() != EOF)
    {
      checkStream(std::cin);
      vec.push_back(getDataFromLine());
    }

    if (std::any_of(vec.begin(), vec.end(), notInRange))
    {
      std::cerr << "ERROR! Value data does not in range!\n";
      return 1;
    }

    std::sort(vec.begin(), vec.end(), CompareLab4());
    std::for_each(vec.begin(), vec.end(), outputData);
  }
  catch (const std::invalid_argument& exc)
  {
    std::cerr << "Catch error [invalid_argument] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (const std::out_of_range& exc)
  {
    std::cerr << "Catch error [out_of_range] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (...)
  {
    std::cerr << "An unrecognized exception occurred in the program!\n";
    return 2;
  }

  return 0;
}
