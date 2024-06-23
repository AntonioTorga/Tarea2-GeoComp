#include "Utils.h"

std::pair<int, int> get_random_pair(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(min, max);
    std::uniform_int_distribution<int> sign(0, 1);
    int sign_x = (sign(gen) == 0) ? 1 : -1;
    int sign_y = (sign(gen) == 0) ? 1 : -1;
    std::pair<int, int> result(dist(gen) * sign_x, dist(gen) * sign_y);

    return result;
}

void Timer::startTimer()
{
    start = std::chrono::high_resolution_clock::now();
    duration = 0.0;
}

void Timer::stop()
{
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    duration = diff.count();
}

double Timer::getDuration() const
{
    return duration;
}

