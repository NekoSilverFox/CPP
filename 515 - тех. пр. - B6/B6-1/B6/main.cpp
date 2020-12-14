#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iomanip>
#include "functor.hpp"
#include "streamFunction.hpp"

int main()
{
  try
  {
    jianing::B6::GetStats get_stats;
    std::for_each(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::ref(get_stats));
    jianing::sf::istreamNotEof(std::cin, "Error input, should be number!\n");
    get_stats.showData(std::cout);
  }
  catch (const std::exception& exc)
  {
    std::cerr << exc.what() << "\n";
    return 1;
  }

  return 0;
}
