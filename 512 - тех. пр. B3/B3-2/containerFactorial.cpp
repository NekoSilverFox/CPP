#include "containerFactorial.hpp"

jianing::ContainerFactorial::Iterator::Iterator() :
  value_(1),
  index_(1)
{}

jianing::ContainerFactorial::Iterator::Iterator(int index) :
  value_(getValue(index)),
  index_(index)
{}

jianing::ContainerFactorial::Iterator::reference jianing::ContainerFactorial::Iterator::operator*()
{
  return value_;
}

jianing::ContainerFactorial::Iterator::pointer jianing::ContainerFactorial::Iterator::operator->()
{
  return &value_;
}

jianing::ContainerFactorial::Iterator& jianing::ContainerFactorial::Iterator::operator++()
{
  index_++;
  value_ = value_ * index_;
  return *this;
}

jianing::ContainerFactorial::Iterator jianing::ContainerFactorial::Iterator::operator++(int)
{
  Iterator tmp = *this;
  ++(*this);
  return tmp;
}

jianing::ContainerFactorial::Iterator& jianing::ContainerFactorial::Iterator::operator--()
{
  if (index_ > 1)
  {
    value_ /= index_;
    --index_;
  }

  return *this;
}

jianing::ContainerFactorial::Iterator jianing::ContainerFactorial::Iterator::operator--(int)
{
  ContainerFactorial::Iterator tmp = *this;
  --(*this);
  return tmp;
}

bool jianing::ContainerFactorial::Iterator::operator==(const ContainerFactorial::Iterator& rhs) const
{
  return ((value_ == rhs.value_) && (index_ == rhs.index_));
}

bool jianing::ContainerFactorial::Iterator::operator!=(const ContainerFactorial::Iterator& rhs) const
{
  return !(*this == rhs);
}

long jianing::ContainerFactorial::Iterator::getValue(int index) const
{
  if (index <= 1)
  {
    return 1;
  }
  else
  {
    return (index * getValue(index - 1));
  }
}

jianing::ContainerFactorial::Iterator jianing::ContainerFactorial::begin()
{
  return Iterator(1);
}

jianing::ContainerFactorial::Iterator jianing::ContainerFactorial::end()
{
  return Iterator(11);
}
