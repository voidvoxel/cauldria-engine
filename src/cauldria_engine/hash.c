#include <stdint.h>

#include <hash.h>

uint32_t djb2 (
    const char *str
)
{
    // Start with a large prime number.
    uint32_t hash = 5381;
    int c;

    // Iterate through each character of the string.
    while ((c = *str++)) {
        // hash = hash * 33 + c
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}
