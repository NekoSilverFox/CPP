#ifndef CONTAINERFACTORIAL_HPP
#define CONTAINERFACTORIAL_HPP
#include <iterator>

namespace jianing
{
  class ContainerFactorial
  {
  public:
    class Iterator : public std::iterator<std::bidirectional_iterator_tag, long>
    {
    public:
      Iterator();
      Iterator(int index);

      long& operator*();
      long* operator->();
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator--(int);
      bool operator==(const Iterator&) const;
      bool operator!=(const Iterator&) const;

    private:
      long value_;
      int index_;
      long getValue(int) const;
    };

    Iterator begin();
    Iterator end();
  };
}
#endif
