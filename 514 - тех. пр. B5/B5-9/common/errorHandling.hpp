#ifndef ERRORHANDLING_HPP
#define ERRORHANDLING_HPP
#include <iostream>
#include <vector>

namespace jianing
{
  class ErrorHanding
  {
  public:
    ErrorHanding() = default;
    const char* getErrorMsg();
    void insertErrorMsg(std::string err_info);
    void pushUnreadStr2ErrMsg(std::istream& istr);
  private:
    std::string err_;
  };

}

extern jianing::ErrorHanding err_msg;

#endif // ERRORHANDLING_HPP
