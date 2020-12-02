#include "streamFunction.hpp"
#include <iostream>

std::istream& jianing::sf::rmw(std::istream& istr)
{
  if (!istr.good())
  {
    return istr;
  }

  while (std::isblank(istr.peek()))
  {
    istr.get();
  }

  return istr;
}
