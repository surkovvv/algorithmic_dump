#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    std::cin >> N;
    vector<int> numbers(N, 0);
    vector<int> mask(N, 0);
    for (size_t i = 0; i < N; i++){
        std::cin >> numbers[i];
        if (i == 0)
            mask[0] = numbers[0] == 0 ? 1 : 0;
        else
            mask[i] = mask[i - 1] + (numbers[i] == 0 ? 1 : 0);
    }
    int K;
    std::cin >> K;
    for (size_t j = 0; j < K; j++){
        int l, r;
        std::cin >> l >> r;
        if (l == 1)
            cout << mask[r - 1] - mask[0] + (numbers[0] == 0 ? 1 : 0) << " ";
        else
            std::cout << mask[r - 1] - mask[l - 1] + (numbers[l - 1] == 0 ? 1 : 0) << " ";
    }
    return 0;
}
