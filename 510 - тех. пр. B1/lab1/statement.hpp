#ifndef STATEMENT_HPP
#define STATEMENT_HPP
#include <iostream>
#include <vector>
#include <forward_list>
#include <cstring>

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

    /*
    ** Local specialization
    */
    template <typename TT>
    struct bracketAccess
    {
      typedef typename TT::size_type indexType;

      static typename TT::reference getElement(TT& data, indexType index)
      {
        return data[index];
      };

      static std::size_t getBegin(const TT&)
      {
        return 0;
      };

      static std::size_t getEnd(const TT& data)
      {
        return data.size();
      };
    };

    template <typename TT>
    struct atAccess
    {
      typedef typename TT::size_type indexType;

      static typename TT::reference getElement(TT& data, indexType index)
      {
        return data.at(index);
      };

      static indexType getBegin(TT&)
      {
        return 0;
      };

      static indexType getEnd(const TT& data)
      {
        return data.size();
      };
    };

    template <typename TT>
    struct iteratorAccess
    {
      typedef typename TT::iterator indexType;

      static typename TT::reference getElement(TT&, indexType index)
      {
        return *index;
      };

      static indexType getBegin(TT& data)
      {
        return data.begin();
      };

      static indexType getEnd(TT& data)
      {
        return data.end();
      };
    };

    template <template <typename TT> class Traits, typename TT>
    void bubbleSort(TT& data, bool (*compare)(typename TT::value_type&, typename TT::value_type&))
    {
      typedef typename Traits<TT>::indexType index;

      for (index i = Traits<TT>::getBegin(data); i != Traits<TT>::getEnd(data); i++)
      {
        for (index j = i; j != Traits<TT>::getEnd(data); j++)
        {
          if (compare(Traits<TT>::getElement(data, i), Traits<TT>::getElement(data, j)))
          {
            std::swap(Traits<TT>::getElement(data, i), Traits<TT>::getElement(data, j));
          }
        }
      }
    }

    template <typename TT>
    void printData(const TT& data)
    {
      for (typename TT::const_iterator it = data.begin(); it != data.end(); it++)
      {
        std::cout << *it << " ";
      }

      std::cout << "\n";
    }
}

#endif // STATEMENT_HPP
