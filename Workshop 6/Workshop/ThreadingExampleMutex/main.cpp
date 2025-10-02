#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include <future>
#include <chrono>

enum LockType {
    None = 0,
    Mutex = 1
};

std::timed_mutex localMutex;

using Ms = std::chrono::milliseconds;
using us = std::chrono::microseconds;

int square(int x) {
    return x * x;
}

void call_from_thread(int threadId, LockType lock) {
    // Mutex version
    if (lock == LockType::Mutex && !localMutex.try_lock_for(Ms(100)))
        return;

    std::stringstream ss1;
    ss1 << "Hello, World from thread: " << threadId << std::endl;
    std::cout << ss1.str();

    if (lock == LockType::Mutex)
        localMutex.unlock();
}

int main() {
    std::cout << "ThreadingExample only use a mutex (or no locking at all) older compilers (C++11/14/17)  \n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl;

    const int num_threads = 10;
    std::thread t[num_threads];

    // Launch a group of threads
    for (int i = 0; i < num_threads; ++i) {
        t[i] = std::thread(call_from_thread, i, LockType::Mutex);
        std::this_thread::sleep_for(us(50));
    }

    // Join the threads with the main thread
    for (int i = 0; i < num_threads; ++i) {
        t[i].join();
    }

#if defined(_DEBUG) && defined(_MSC_FULL_VER)
    __debugbreak(); // hardcoded breakpoint for debug build only
#endif
    return 0;
}
