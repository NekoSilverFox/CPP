#include "errorHandling.hpp"
#include <iostream>

jianing::ErrorHanding err_msg;

const char* jianing::ErrorHanding::getErrorMsg()
{
  return err_.c_str();
}

void jianing::ErrorHanding::insertErrorMsg(std::string err_info)
{
  err_.insert(0, "\n" + err_info);
}

void jianing::ErrorHanding::pushUnreadStr2ErrMsg(std::istream& istr)
{
  if (!istr.eof())
  {
    auto old_state = istr.rdstate();

    istr.clear();
    std::string unread_str;
    std::getline(istr, unread_str);
    err_.insert(0, "\nError input near (unread string) `<" + unread_str + ">...`:");

    istr.setstate(old_state);
  }
}
