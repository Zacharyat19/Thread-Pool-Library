#pragma once

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool {
public:
    // Constructor: create a pool with a fixed number of threads
    explicit ThreadPool(size_t numThreads);

    // Destructor: clean up threads
    ~ThreadPool();

    // Submit a void task (no return value, no arguments)
    void enqueue(const std::function<void()>& task);

private:
    // Worker threads
    std::vector<std::thread> workers;

    // Task queue
    std::queue<std::function<void()>> tasks;

    // Synchronization
    std::mutex queueMutex;
    std::condition_variable condition;

    // Control flag
    bool stop;
};
