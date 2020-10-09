#include "allSubjects.hpp"
#include <vector>
#include <fstream>
#include <memory>
#include "statement.hpp"

void jianing::subject2(const char* filename)
{
  std::ifstream input_file(filename, std::ios_base::binary);

  if (input_file.good() == 0)
  {
    throw std::invalid_argument("ERROR! Unrecognized file name!\n");
  }
  
  /*
  ** Check `failbit` status flag
  */
  if (std::cin.bad())
  {
    throw std::ios_base::failure("ERROR! A serious exception occurred in the import stream (in subject2)!\n");
  }
  else if (input_file.fail())
  {
    throw std::ios_base::failure("ERROR! An error occurred while closing the file (in subject2)!\n");
  }

  size_t size = 0;
  size_t content_capacity = 64;
  std::unique_ptr<char[], decltype(&free)> contents(static_cast<char*>(malloc(content_capacity)), free);

  while (input_file)
  {
    input_file.read(&contents[size], content_capacity - size);
    size += input_file.gcount();

    if (size == content_capacity)
    {
      content_capacity *= 2;
      auto temp_content = contents.release();
      contents.reset(static_cast<char*>(std::realloc(temp_content, content_capacity)));

      if (!contents)
      {
        throw std::runtime_error("ERROR! Memory allocation is abnormal!\n");
      }
    }
  }

  input_file.close();

  if (input_file.is_open())
  {
    throw std::invalid_argument("ERROR! The file did not close!\n");
  }


  std::vector<char> vec(&contents[0], &contents[size]);

  for (char& it : vec) // width
  {
    std::cout << it;
  }
}
