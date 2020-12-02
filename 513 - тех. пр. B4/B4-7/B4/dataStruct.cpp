#include "dataStruct.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "streamFunction.hpp"

bool jianing::B4::Compare::operator()(const DataStruct& l_val, const DataStruct& r_val) const
{
  if (l_val.key1 == r_val.key1)
  {
    if (l_val.key2 == r_val.key2)
    {
      return (l_val.str.size() < r_val.str.size());
    }
    return (l_val.key2 < r_val.key2);
  }
  return (l_val.key1 < r_val.key1);
}

bool jianing::B4::anomalyData(const DataStruct& data)
{
  return !(
              ((data.key1 >= MIN_VAL) && (data.key1 <= MAX_VAL))
           && ((data.key2 >= MIN_VAL) && (data.key2 <= MAX_VAL))
           && !data.str.empty()
          );
}

/*
 * Note: This function removes this character while checking for the next character in the input stream.
 */
std::istream& jianing::B4::checkNextSign(std::istream& istr, const char c_sign)
{
  if (!istr.good())
  {
    return istr;
  }

  if ((istr.get() != c_sign) || (istr.peek() == '\n'))
  {
    istr.setstate(std::istream::failbit);
    return istr;
  }

  return istr;
}

jianing::B4::DataStruct jianing::B4::readData(std::istream& istr)
{
  if (!istr.good())
  {
    istr.setstate(std::istream::failbit);
  }

  DataStruct tmp_data = {0, 0, ""};

  istr >> tmp_data.key1 >> jianing::sf::rmw;
  checkNextSign(istr, ',');

  istr >> tmp_data.key2 >> jianing::sf::rmw;
  checkNextSign(istr, ',');

  std::getline(istr, tmp_data.str);
  if (istr.fail() || anomalyData(tmp_data))
  {
    istr.setstate(std::istream::failbit);
  }

  return tmp_data;
}

std::istream& jianing::B4::operator>>(std::istream& istr, DataStruct& data)
{
  if (!istr.good())
  {
    return istr;
  }

  DataStruct tmp_data = {0, 0, ""};
  tmp_data = readData(istr);

  if (istr.good())
  {
    data = tmp_data;
  }

  return istr;
}

std::ostream& jianing::B4::operator<<(std::ostream& ostr, const DataStruct& data)
{
  if (ostr.good())
  {
    ostr << data.key1 << ',' << data.key2 << ',' << data.str;
  }

  return ostr;
}
