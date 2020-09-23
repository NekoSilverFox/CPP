#ifndef STATEMENT_HPP
#define STATEMENT_HPP
#include <iostream>

void subject1(const char* sort_type);
void subject2(const char* filename);
void subject3();
void subject4(const char* sort_type, const char* array_size);

namespace jianing
{
    template <typename T>
    bool greater(T left, T right)
    {
      return left > right;
    }

    template <typename T>
    bool less(T left, T right)
    {
      return left < right;
    }

    template <typename T>
    struct bracketAccess
    {
      static typename T::reference getElement(T& data, std::size_t index)
      {
        return data[index];
      };

      static std::size_t getBegin(const T&)
      {
        return 0;
      };

      static std::size_t getEnd(const T& data)
      {
        return data.size();
      };
    };

    template <typename T>
    struct atAccess
    {
      typedef typename T::size_type indexType;

      static typename T::reference getElement(T& data, indexType index)
      {
        return data.at(index);
      };

      static indexType getBegin(T&)
      {
        return 0;
      };

      static indexType getEnd(const T& data)
      {
        return data.size();
      };
    };

    template <typename T>
    struct iteratorAccess
    {
      typedef typename T::iterator indexType;

      static typename T::reference getElement(T&, indexType index)
      {
        return *index;
      };

      static indexType getBegin(T& data)
      {
        return data.begin();
      };

      static indexType getEnd(T& data)
      {
        return data.end();
      };
    };

    template <template <typename T> class Traits, typename T>
    void bubbleSort(T& data, bool (*compare)(typename T::value_type&, typename T::value_type&))
    {
      typedef typename Traits<T>::indexType index;

      for (index i = Traits<T>::getBegin(data); i != Traits<T>::getEnd(data); i++)
      {
        for (index j = i; j != Traits<T>::getEnd(data); j++)
        {
          if (compare(Traits<T>::getElement(data, i), Traits<T>::getElement(data, j)))
          {
            std::swap(Traits<T>::getElement(data, i), Traits<T>::getElement(data, j));
          }
        }
      }
    }

    template <typename T>
    void printData(const T& data)
    {
      for (typename T::const_iterator it = data.begin(); it != data.end(); it++)
      {
        std::cout << *it << " ";
      }

      std::cout << "\n";
    }
}
#endif // STATEMENT_HPP
