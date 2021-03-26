
//
// Created by drax on 21.03.21.
//

#ifndef ECHO_SERVER_MY_TIME_H
#define ECHO_SERVER_MY_TIME_H

#include <chrono>
#include <atomic>


inline std::chrono::high_resolution_clock::time_point get_current_time()
{
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template<class D>
inline long long to_us(const D& d)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}


#endif //ECHO_SERVER_MY_TIME_H
