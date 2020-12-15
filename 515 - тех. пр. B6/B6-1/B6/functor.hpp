#ifndef FUNCTOR_HPP
#define FUNCTOR_HPP
#include <iostream>

namespace jianing
{
  namespace B6
  {
    class GetStats
    {
    public:
      GetStats();
      void operator()(int val);
      void showData(std::ostream& ostr);
    private:
      int max_;
      int min_;
      int positive_;
      int negative_;
      int first_;
      int last_;
      int count_;
      long long odd_sum_;
      long long even_sum_;
      double mean_;
    };
  }
}

#endif
