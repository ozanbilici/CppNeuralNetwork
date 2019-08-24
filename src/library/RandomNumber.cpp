#include <cstdlib>
#include <ctime>

#include "RandomNumber.hpp"

RandomNumber::RandomNumber(std::uint32_t seed)
{
    m_seed = seed;

    /* initialize random seed: */
    srand(m_seed);
}

double RandomNumber::generateNumber()
{
    return (double) rand() / (RAND_MAX);
}