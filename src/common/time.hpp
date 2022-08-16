#ifndef RY_TIME_HPP
#define RY_TIME_HPP

#include <chrono>

namespace timings  {
    long millisec_since_epoch()  {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count();
    }

    long elapsed_time(long previous_ms)   {
        return millisec_since_epoch() - previous_ms;
    }
}

#endif