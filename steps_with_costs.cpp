#include <iostream>

int main() {
    size_t N;
    std::cin >> N;
    auto* v = new unsigned int[N];
    auto *costs = new unsigned int[N];
    for (size_t i = 0; i < N; i++)
        std::cin >> costs[i];
    v[0] = costs[0];
    if (N == 1) {
        std::cout << 0;
        return 0;
    }
    v[1] = costs[1];
    for (size_t i = 2; i < N; i++)
        v[i] = std::min(v[i - 1], v[i - 2]) + costs[i];
    std::cout << std::min(v[N - 1], v[N - 2]);
    return 0;
}
