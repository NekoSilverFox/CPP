#include "streamFunction.hpp"
#include <iostream>

std::istream& jianing::sf::rmw(std::istream& istr)
{
  if (!istr.good())
  {
    return istr;
  }

  while (
            (istr.peek() == ' ')
         || (istr.peek() == '\t')
         || (istr.peek() == '\0')
         )
  {
    istr.get();
  }

  return istr;
}
