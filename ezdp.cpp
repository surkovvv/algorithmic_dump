#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t N, M;
    cin >> N >> M;
    vector<vector<int64_t>> v(N, vector<int64_t>(M));
    v[0][0] = 1;
    for (size_t col = 1; col < M; col ++)
        v[0][col] = 1;
    for (size_t row = 1; row < N; row ++)
        v[row][0] = 1;
    for (size_t i = 1; i < N; i++){
        for (size_t j = 1; j < M; j++)
            v[i][j] = v[i - 1][j] + v[i][j - 1];
    }
    cout << v[N - 1][M - 1];
    return 0;
}
