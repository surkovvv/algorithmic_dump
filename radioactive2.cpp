#include <iostream>

int main() {
    int N;
    std::cin >> N;
    unsigned int* v = new unsigned int[N + 1];
    v[1] = 3;
    v[2] = 8;
    for (size_t i = 3; i <= N; i++)
        v[i] = 2 * (v[i - 1] + v[i - 2]);
    std::cout << v[N];
    return 0;
}
