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