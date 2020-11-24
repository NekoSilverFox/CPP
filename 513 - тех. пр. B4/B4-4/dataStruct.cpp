#include "dataStruct.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>

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

bool jianing::B4::notInRange(const DataStruct& data)
{
  using namespace jianing::B4::val;
  return !(
              ((data.key1 >= MIN_VAL) && (data.key1 <= MAX_VAL))
           && ((data.key2 >= MIN_VAL) && (data.key2 <= MAX_VAL))
           && !data.str.empty()
          );
}

std::istream& jianing::B4::operator>>(std::istream& istr, DataStruct& data)
{
  std::string str_line;
  std::getline(istr, str_line);
  std::stringstream str_stream(str_line);

  str_stream >> data.key1;

  if (str_stream.get() != ',')
  {
    istr.setstate(std::istream::failbit);
    return istr;
  }
  str_stream >> data.key2;

  if (str_stream.get() != ',')
  {
    istr.setstate(std::istream::failbit);
    return istr;
  }
  std::getline(str_stream, data.str);

  if (str_stream.fail() || notInRange(data))
  {
    istr.setstate(std::istream::failbit);
  }

  return istr;
}

std::ostream& jianing::B4::operator<<(std::ostream& ostr, const DataStruct& data)
{
  if (ostr.fail())
  {
    ostr.setstate(std::ostream::goodbit);
  }

  ostr << data.key1 << ',' << data.key2 << ',' << data.str;

  return ostr;
}
