#include "Txt.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace l1;

Txt::Txt()
    :array()
{

}

Txt::Txt(const std::string& fileName)
    :Txt()
{
    std::ifstream in(fileName.c_str());

    if (!in)
    {
        std::cerr << "Cannot open the File : " << fileName << std::endl;
    }
    else
    {
        std::string str;
        // Read the next line from File untill it reaches the end.
        while (std::getline(in, str))
        {
            // Line contains string of length > 0 then save it in vector
            if (str.size() > 0)
                array.push_back(str);
        }
    }
}

Txt::~Txt()
{

}

Txt::Txt(const Txt& other)
{
    this->array = other.array;
}

Txt& Txt::operator=(const Txt& other)
{
    array = other.array;
    return *this;
}

Txt::Txt(Txt&& other) noexcept
    :array(std::move(other.array))
{
}

Txt& Txt::operator=(Txt&& other) noexcept
{
    if (&other == this)
        return *this;

    array = std::move(other.array);
    return *this;
}

size_t l1::Txt::size()
{
    return array.size();
}