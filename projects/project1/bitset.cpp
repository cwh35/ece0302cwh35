#include "bitset.hpp"

Bitset::Bitset()
{
    BitArray = new int[8];
    for (int i=0; i<8; i++)
    {
        BitArray[i] = 0; //fills array with zeros
    }
}
Bitset::Bitset(intmax_t size)
{
    if (size > 0)
    {
        isValid = true;
    }
    //sets size of array to parameter
    BitArray[size]; 
    for(int i=0; i<size; i++)
    {
        BitArray[i] = 0; //fills array with zeros
    }
}
Bitset::Bitset(const std::string & value)
{
    int arrayLength = value.length();
    BitArray = new int[arrayLength];
    isValid = true;
    
    for(int i=0; i<arrayLength; i++) //For loop to assign values in the string to 1 or 0
    {
        if (value[i] == '0')
        {
            BitArray[i] = 0;
        }
        if (value[i] == '1')
        {
            BitArray[i] = 1;
        }
        else
        {
            isValid = false;
        }
    }
}
bool Bitset::good() const
{
    return isValid;
}
intmax_t Bitset::size() const
{
    
}