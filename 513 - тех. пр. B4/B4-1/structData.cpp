#include "dataStruct.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>

bool lessThan(const DataStruct& l_val, const DataStruct& r_val)
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

DataStruct getDataFromLine()
{
  std::string str_line;
  std::getline(std::cin, str_line);
  std::stringstream str_stream(str_line);

  DataStruct data;
  str_stream >> data.key1;

  str_stream.ignore(std::numeric_limits<std::streamsize>::max(), ',');
  str_stream >> data.key2;

  str_stream.ignore(std::numeric_limits<std::streamsize>::max(), ',');
  std::getline(str_stream, data.str);

  if (str_stream.fail())
  {
    throw std::invalid_argument("ERROR! Invalid input");
  }
  return data;
}

void outputData(DataStruct& data)
{
  std::cout << data.key1 << ',' << data.key2 << ',' << data.str << "\n";
}

bool notInRange(const DataStruct& data)
{
  return !(
              ((data.key1 >= val_lab5::MIN_VAL) && (data.key1 <= val_lab5::MAX_VAL))
           && ((data.key2 >= val_lab5::MIN_VAL) && (data.key2 <= val_lab5::MAX_VAL))
          );
}
