#ifndef DATASTRUCT_HPP
#define DATASTRUCT_HPP
#include <string>
#include <vector>

namespace jianing
{
  namespace B4
  {
    namespace val
    {
      const int MIN_VAL = -5;
      const int MAX_VAL = 5;
    }

    struct DataStruct
    {
      int key1;
      int key2;
      std::string str;

      friend std::istream& operator>>(std::istream& istr, DataStruct& data);
      friend std::ostream& operator<<(std::ostream& ostr, const DataStruct& data);
    };

    class Compare
    {
    public:
      bool operator()(const DataStruct& l_val, const DataStruct& r_val) const;
    };

    std::istream& operator>>(std::istream& istr, DataStruct& data);
    std::ostream& operator<<(std::ostream& ostr, const DataStruct& data);

    void readData(std::istream& istr, DataStruct& data);
    bool notInRange(const DataStruct& data);
  }
}
#endif // DATASTRUCT_HPP
