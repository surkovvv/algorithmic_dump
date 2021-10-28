#include <iostream>

int main() {
    int N;
    std::cin >> N;
    unsigned int* v = new unsigned int[N + 1];
    v[N - 1] = 1; v[N] = 1;
    if (N > 1)
        v[N - 2] = 2;
    for (int i = N - 3; i >= 0; i--)
        v[i] = v[i + 1] + v[i + 2] + v[i + 3];
    std::cout << v[0];
    return 0;
}
