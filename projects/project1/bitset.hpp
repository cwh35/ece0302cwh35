#ifndef BITSET_HPP
#define BITSET_HPP

#include <string>

class Bitset{
public:

  // Default constructor that creates a valid bitset of size 8
  // All bits are set to 0
  Bitset();

  // Constructor that creates a bitset with the inputted size as a parameter
  Bitset(intmax_t size);

  // Assigns an integer value to a single character, checks if the character is 0 or 1
  Bitset(const std::string & value);

  // Destructor - Destroys the array after the code is finished
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // Returns the size of the bitset
  intmax_t size() const;

  // Returns the boolean variable "isValid" set equal to true
  bool good() const;

  // Sets nth bit to 1, tests if index is in the range [0, N-1]
  void set(intmax_t index);

  // Sets nth bit to 0, tests if index is in the range [0, N-1]
  void reset(intmax_t index);

  // Toggles the nth bit from 0 to 1 or 1 to 0, tests if index is in the range [0, N-1]
  void toggle(intmax_t index);

  // Returns true if nth bit is 1, false if 0, tests if index is in the range [0, N-1]
  bool test(intmax_t index);

  // Converts the bitset to a string value of "0" or "1" and returns it
  std::string asString() const;

private:
  int *BitArray;
  bool isValid;
  int arraySize;
};

#endif