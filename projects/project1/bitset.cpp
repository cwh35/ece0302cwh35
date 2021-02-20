#include "bitset.hpp"

Bitset::Bitset()
{
    arraySize = 8;
    BitArray = new int[arraySize];
    for (int i=0; i<arraySize; i++)
    {
        BitArray[i] = 0; //fills array with zeros
    }
    isValid = true;
}
Bitset::Bitset(intmax_t size)
{
    BitArray = new int[size];
    arraySize = size;
    if (arraySize < 0)
    {
        isValid = false;
    }
    else
    {
        isValid = true;
    }
    
    //sets size of array to parameter
    BitArray[arraySize]; 
    for(int i=0; i<arraySize; i++)
    {
        BitArray[i] = 0; //fills array with zeros
    }
}
Bitset::Bitset(const std::string & value)
{
    arraySize = value.length();
    BitArray = new int[arraySize];
    
    for(int i=0; i<arraySize; i++) //For loop to assign values in the string to 1 or 0
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
    isValid = true;
}
bool Bitset::good() const
{
    return isValid;
}
Bitset::~Bitset()
{
    delete [] BitArray; //Deletes bit array
}
intmax_t Bitset::size() const
{
    return arraySize; //Returns array size
}
void Bitset::set(intmax_t index)
{
    if ((index < 0) || (index > arraySize))
    {
        isValid = false;
    }
    if (index<arraySize)
    {
        BitArray[index] = 1; //Sets only the number at index to 1
    }
}
void Bitset::reset(intmax_t index)
{
    if ((index < 0) || (index > arraySize))
    {
        isValid = false;
    }
    if (index<arraySize)
    {
        BitArray[index] = 0; //Sets only the number at index to 0
    }
}
void Bitset::toggle(intmax_t index)
{
    if ((index < 0) || (index > arraySize))
    {
        isValid = false;
    }
    if (BitArray[index] == 1) //Toggles the nth bit
    {
        BitArray[index] = 0;
    }
    else
    {
        BitArray[index] = 1;
    }
}
 bool Bitset::test(intmax_t index)
 {
    if ((index < 0) || (index > arraySize))
    {
        isValid = false;
    }
     if (BitArray[index] == 1) 
    {
        return true;
    }
    else
    {
        return false;
    }
 }
std::string Bitset::asString() const
{
    std::string temp;
    for (int i=0; i<arraySize; i++)
    {
        if (BitArray[i] == 0)
        {
            temp.replace(i, 1, "0");
        }
        else 
        {
            temp.replace(i, 1, "1");
        }
    }
    return temp; 
}