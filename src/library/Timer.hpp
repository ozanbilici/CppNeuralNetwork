#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <cstdint>
#include <iostream>

class Timer
{
public:
    /**
     * @brief Constructor of timer for run time test
     */
    Timer()
    {
        m_start = std::chrono::high_resolution_clock::now();
    }

    /**
     * @brief Destructor
     */
    ~Timer()
    {
        auto end = std::chrono::high_resolution_clock::now();

        auto start_us = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
        auto end_us = std::chrono::time_point_cast<std::chrono::microseconds>(end).time_since_epoch().count();

        auto duration_us = end_us - start_us;
        auto duration_ms = duration_us * 0.001;

        std::cout << "Duration: " << duration_us << " us ( " << duration_ms << " ms) \n";
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
};

#endif // TIMER_HPP