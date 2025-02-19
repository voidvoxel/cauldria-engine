#include <stdint.h>
#include <iostream>
#include <sstream>
#include <string>

#include "utils.hpp"

std::string voidvoxel::cauldria::toHex(int32_t value)
{
    // Create a new string stream.
    std::ostringstream stringStream;

    // Pass the value through the hex filter and into the string stream.
    stringStream << std::hex << value;

    // Return the result.
    return stringStream.str();
}
