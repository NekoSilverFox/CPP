#ifndef DATASTRUCT_HPP
#define DATASTRUCT_HPP
#include <iterator>
#include <string>
#include <vector>

/*
 * const
 */
namespace jianing
{
  namespace B4
  {
    const int MIN_VAL = -5;
    const int MAX_VAL = 5;
  }
}

/*
 * struct and class
 */
namespace jianing
{
  namespace B4
  {
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
  }
}

/*
 * function
 */
namespace jianing
{
  namespace B4
  {
    std::istream& operator>>(std::istream& istr, DataStruct& data);
    std::ostream& operator<<(std::ostream& ostr, const DataStruct& data);

    void readData(std::istream& istr, DataStruct& data);
    bool anomalyData(const DataStruct& data);

    /*
     * Note: This function removes this character while checking for the next character in the input stream.
     */
    std::istream& checkNextSign(std::istream& istr, const char c_sign);
  }
}

/*
 * sig - sigillum
 */
namespace jianing
{
  namespace B4
  {
    namespace sig
    {
      using ds_istr_iter = std::istream_iterator<DataStruct>;
      using ds_ostr_iter = std::ostream_iterator<DataStruct>;
    }
  }
}

#endif // DATASTRUCT_HPP
