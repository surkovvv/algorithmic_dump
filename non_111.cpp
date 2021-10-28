#include <iostream>

int main() {
    int N;
    std::cin >> N;
    unsigned int* v = new unsigned int[N + 1];
    v[1] = 2;
    v[2] = 4;
    v[3] = 7;
    for (size_t i = 4; i <= N; i++)
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    std::cout << v[N];
    return 0;
}
