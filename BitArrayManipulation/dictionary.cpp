// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "dictionary.h"

Dictionary::Dictionary() : data_(0), lookupTable_(nullptr) {}

Dictionary::Dictionary(const Dictionary &dict)
{
  // Copy the BitArray
  data_ = dict.data_;
  // Copy the Lookup Table
  lookupTable_ = new int[DICTIONARY_SIZE];
  for (int i = 0; i < DICTIONARY_SIZE; i++)
  {
    lookupTable_[i] = dict.lookupTable_[i];
  }
}

Dictionary::~Dictionary()
{
  delete[] lookupTable_;
}

void Dictionary::initialize(char *word, int size)
{
  data_.initialize(word, size);
  delete[] lookupTable_; // Delete any existing lookup table
  lookupTable_ = new int[DICTIONARY_SIZE];
  if (!loadLookupTable("lookupTable.txt")) // in case file can't be opened
  {
    for (int i = 0; i < DICTIONARY_SIZE; i++)
    {
      lookupTable_[i] = countOnes(static_cast<char>(i)); // countOnes is a helper method
    }
  }
}

int Dictionary::rank_range(int start, int end, int bit)
{
  return rank(end, bit) - rank(start, bit);
}

int Dictionary::select_range(int start, int end, int k, int bit)
{
  int i = start;
  while (i < end && i % 8 != 0)
  {
    if (data_.get(i) == bit)
    {
      if (k == 1)
      {
        return i;
      }
      k--;
    }
    i++;
  }

  // Complete bytes portion
  while (i + 8 <= end)
  {
    unsigned char byte = static_cast<unsigned char>(data_.get8(i / 8));
    int matches = lookupTable_[byte];
    if (bit == 0)
    {
      matches = 8 - matches;
    }

    // this is executed when the desired bit is inferred to be in current byte
    if (k <= matches)
    {
      for (int j = 0; j < 8; j++)
      {
        int position = i + j;

        if (data_.get(position) == bit)
        {
          if (k == 1)
          {
            return position;
          }
          k--;
        }
      }
    }
    else // skip the whole byte
    {
      k -= matches;
    }
    i += 8;
  }

  // handle leftover bits
  while (i < end)
  {
    if (data_.get(i) == bit)
    {
      if (k == 1)
      {
        return i;
      }
      k--;
    }
    i++;
  }

  return -1;
}

int Dictionary::rank(int end, int bit)
{
  int i, count = 0;
  int fullBytes = end / 8;
  int remainingBits = end % 8;

  for (i = 0; i < fullBytes; i++)
  {
    unsigned char byte = static_cast<unsigned char>(data_.get8(i));
    if (bit == 1)
    {
      count += lookupTable_[byte];
    }
    else
    {
      count += 8 - lookupTable_[byte];
    }
  }

  int start = fullBytes * 8;
  for (i = 0; i < remainingBits; i++)
  {
    if (data_.get(start + i) == bit)
    {
      count++;
    }
  }

  return count;
}

int Dictionary::select(int k, int bit)
{
  return select_range(0, data_.length(), k, bit);
}

void Dictionary::printLookupTable(std::ostream &output)
{
  for (int i = 0; i < DICTIONARY_SIZE; i++)
  {
    output << "lookupTable_[" << i << "] "
           << lookupTable_[i] << std::endl;
  }
}

int Dictionary::countOnes(char byte)
{
  int i, count = 0;

  unsigned char value = static_cast<unsigned char>(byte);

  for (i = 0; i < 8; i++)
  {
    if (value & (1 << i))
    {
      count++;
    }
  }

  return count;
}

BitArray &Dictionary::getData()
{
  return data_;
}

bool Dictionary::loadLookupTable(const char *file)
{
  std::ifstream input(file);

  if (!input)
  {
    return false;
  }

  for (int i = 0; i < DICTIONARY_SIZE; i++)
  {
    if (!(input >> lookupTable_[i]))
    {
      return false;
    }
  }
  return true;
}