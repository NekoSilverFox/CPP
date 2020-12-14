#include "functor.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>

namespace jianing
{
  namespace B6
  {
    const char* S_NO_DATA = "No Data";
    const char* S_MAX = "Max: ";
    const char* S_MIN = "Min: ";
    const char* S_MEAN = "Mean: ";
    const char* S_POS = "Positive: ";
    const char* S_NEG = "Negative: ";
    const char* S_ODD_SUM = "Odd Sum: ";
    const char* S_EVEN_SUM = "Even Sum: ";
    const char* S_FIR_LAST_EQU = "First/Last Equal: ";
  }
}

jianing::B6::GetStats::GetStats() :
  max_(std::numeric_limits<int>::min()),
  min_(std::numeric_limits<int>::max()),
  positive_(0),
  negative_(0),
  count_(0),
  odd_sum_(0),
  even_sum_(0),
  mean_(0.0)
{}

void jianing::B6::GetStats::operator()(int val)
{
  max_ = std::max(max_, val);
  min_ = std::min(min_, val);

  if (val > 0)
  {
    positive_++;
  }
  else if (val < 0)
  {
    negative_++;
  }

  if (val % 2 == 0)
  {
    even_sum_ += val;
  }
  else
  {
    odd_sum_ += val;
  }

  if (count_ == 0)
  {
    first_ = val;
  }

  last_ = val;
  count_++;
  mean_ = static_cast<double>(even_sum_ + odd_sum_) / static_cast<double>(count_);
}

void jianing::B6::GetStats::showData(std::ostream& ostr)
{
  if (count_ == 0)
  {
    ostr << S_NO_DATA << "\n";
    return;
  }

  ostr << S_MAX << max_ << "\n"
       << S_MIN << min_ << "\n"
       << S_MEAN << std::setprecision(1) << std::fixed << mean_ << "\n"
       << S_POS << positive_ << "\n"
       << S_NEG << negative_ << "\n"
       << S_ODD_SUM << odd_sum_ << "\n"
       << S_EVEN_SUM << even_sum_ << "\n"
       << S_FIR_LAST_EQU << (first_ == last_ ? "yes" : "no") << "\n";
}
