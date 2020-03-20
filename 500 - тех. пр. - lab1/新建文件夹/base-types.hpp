#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
#include<iostream>

// ------------------------------ ERROR INFO ------------------------------
class MyErrorInfo
{
public:
  MyErrorInfo(char* errorInfo)
  {
    this->m_error = errorInfo;
  }
  ~MyErrorInfo() {}
  virtual const char* what()
  {
  return this->m_error;
  }
private:
  char* m_error;
};
// ----------------------------------------------------------------------------
struct point_t
{
  double x, y;
};
struct rectangle_t
{
  double width, height;
  point_t pos;
};
#endif
