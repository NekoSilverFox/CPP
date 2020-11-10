#ifndef DATASTRUCT_HPP
#define DATASTRUCT_HPP
#include <string>

namespace val_lab5
{
  const int MIN_VAL = -5;
  const int MAX_VAL = 5;
}

struct DataStruct
{
  int key1;
  int key2;
  std::string str;
};

bool lessThan(const DataStruct& l_val, const DataStruct& r_val);
DataStruct getDataFromLine();
void outputData(DataStruct& data);
bool notInRange(const DataStruct& data);

#endif // DATASTRUCT_HPP
