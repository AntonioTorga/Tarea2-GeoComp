#pragma once

#include <vector>
#include <random>
#include <utility>
#include <chrono>
#include <functional>

std::pair<int, int> get_random_pair(int max, int min);

class Timer {
public:
    Timer() : start(std::chrono::high_resolution_clock::now()), duration(0.0) {}

    void startTimer();

    void stop();

    double getDuration() const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    double duration;
};