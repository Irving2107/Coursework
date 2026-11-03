// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "bitarray.h"

void BitArray::print()
{
  std::cout << "|";
  for (int i = 0; i < BYTES; i++)
  {
    std::bitset<BIT_IN_BYTE> bits = data_[i];
    std::cout << bits << "|";
  }
  std::cout << std::endl;
}

BitArray::BitArray(int size) // BYTES is (size + BIT_IN_BYTE - 1) / BIT_IN_BYTE to round UP to the nearest byte
    : LENGTH(size), BYTES((size + BIT_IN_BYTE - 1) / BIT_IN_BYTE)
{
  data_ = new char[BYTES];
  clear();
}

BitArray::BitArray(const BitArray &array)
    : LENGTH(array.LENGTH), BYTES(array.BYTES)
{
  data_ = new char[BYTES];
  for (int i = 0; i < BYTES; i++)
  {
    data_[i] = array.data_[i];
  }
}

BitArray::~BitArray()
{
  delete[] data_;
}

bool BitArray::get(int position) const
{
  if (position < 0 || position >= LENGTH)
  {
    return false;
  }
  int byteIndex = position / BIT_IN_BYTE;
  // This counts the bit from left to right, so we need to subtract from BIT_IN_BYTE - 1 to get the correct bit index
  int bitIndex = BIT_IN_BYTE - 1 - (position % BIT_IN_BYTE);
  // Shift the byte to the right by bitIndex and mask with 1 to get the bit value
  return (data_[byteIndex] >> bitIndex) & 1;
}

void BitArray::clear()
{
  for (int i = 0; i < BYTES; i++)
  {
    data_[i] = 0;
  }
}

void BitArray::initialize(char *word, int size)
{
  LENGTH = size;
  BYTES = (size + BIT_IN_BYTE - 1) / BIT_IN_BYTE;
  delete[] data_;
  data_ = new char[BYTES];
  // This ensures we don't access out of bounds
  if (word != nullptr)
  {
    for (int i = 0; i < BYTES; i++)
    {
      data_[i] = word[i];
    }
  }
}

bool BitArray::set(int position, int bit)
{
  if (position < 0 || position >= LENGTH || (bit != 0 && bit != 1))
  {
    return false;
  }
  int byteIndex = position / BIT_IN_BYTE;
  // This counts the bit from left to right, so we need to subtract from BIT_IN_BYTE - 1 to get the correct bit index
  int bitIndex = BIT_IN_BYTE - 1 - (position % BIT_IN_BYTE);
  if (bit == 1)
  {
    // Set the bit to 1
    data_[byteIndex] |= (1 << bitIndex);
  }
  else
  {
    // Set the bit to 0
    data_[byteIndex] &= ~(1 << bitIndex);
  }
  return true;
}

bool BitArray::flip(int position)
{
  if (position < 0 || position >= LENGTH)
  {
    return false;
  }
  int byteIndex = position / BIT_IN_BYTE;
  // This counts the bit from left to right, so we need to subtract from BIT_IN_BYTE - 1 to get the correct bit index
  int bitIndex = BIT_IN_BYTE - 1 - (position % BIT_IN_BYTE);
  // XOR the bit with 1 to flip it
  data_[byteIndex] ^= (1 << bitIndex);
  return true;
}

void BitArray::complement()
{
  for (int i = 0; i < BYTES; i++)
  {
    // ~ is the bitwise NOT operator
    data_[i] = ~data_[i];
  }
}

char BitArray::get8(int position) const
{
  if (position < 0 || position >= BYTES)
  {
    return 0;
  }
  return data_[position];
}

void BitArray::set8(char c, int index)
{
  if (index < 0 || index >= BYTES)
  {
    return;
  }
  data_[index] = c;
}