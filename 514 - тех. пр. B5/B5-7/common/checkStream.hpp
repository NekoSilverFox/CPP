#ifndef CHECKSTREAM_HPP
#define CHECKSTREAM_HPP
#include <iostream>

bool checkStream(const std::istream& stream_in)
{
  if (stream_in.fail())
  {
    throw std::invalid_argument("ERROR! The value is too large to processing!\n");
  }

  if (stream_in.bad())
  {
    throw std::ios_base::failure("ERROR! A serious exception occurred in the import stream (in task1)!\n");
  }

  return true;
}

#endif // CHECKSTREAM_HPP
