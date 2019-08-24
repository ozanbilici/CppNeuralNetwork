#ifndef RANDOM_NUMBER_HPP
#define RANDOM_NUMBER_HPP

#include <cstdint>

class RandomNumber
{
public:
    /**
     * @brief Random number generator
     *
     * @param [in] seed
     *  Seed value
     */
    RandomNumber(std::uint32_t seed);

    /**
     * @brief Random number generator
     *
     * @returns
     *  Returns random number between 0 and 1
     */
    double generateNumber();
private:
    uint32_t m_seed;
};

#endif // RANDOM_NUMBER_HPP