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

void jianing::sf::istreamNotEof(std::istream& istr, const char* err_msg)
{
  if (!istr.eof())
  {
    throw std::invalid_argument(err_msg);
  }
}

void jianing::sf::istreamNotEofAndFail(std::istream& istr, const char* err_msg)
{
  if (!istr.eof() && istr.fail())
  {
    throw std::runtime_error(err_msg);
  }
}

void jianing::sf::istreamBad(std::istream& istr, const char* err_msg)
{
  if (istr.bad())
  {
    throw std::runtime_error(err_msg);
  }
}
