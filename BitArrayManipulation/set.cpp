// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "set.h"

Set::Set(int size) : data_(size) {}

Set::~Set() {}

void Set::initialize(char *word, int size)
{
  data_.initialize(word, size);
}

int Set::getCardinality() const
{
  int count = 0;
  for (int i = 0; i < data_.length(); i++)
  {
    // Count the number of 1's in the underlying BitArray
    if (data_.get(i))
    {
      count++;
    }
  }
  return count;
}

BitArray &Set::getData()
{
  return data_;
}

bool Set::setUnion(Set &B)
{
  // Only works if the two sets have the same length
  if (data_.length() != B.getData().length())
  {
    return false;
  }

  for (int i = 0; i < data_.length(); i++)
  {
    // If the bit in B is set, set the corresponding bit in this set
    if (B.getData().get(i))
    {
      data_.set(i);
    }
  }
  return true;
}

bool Set::setIntersection(Set &B)
{
  // Only works if the two sets have the same length
  if (data_.length() != B.getData().length())
  {
    return false;
  }

  for (int i = 0; i < data_.length(); i++)
  {
    // If the bit in B is not set, clear the corresponding bit in this set
    if (!B.getData().get(i))
    {
      data_.set(i, 0);
    }
  }
  return true;
}