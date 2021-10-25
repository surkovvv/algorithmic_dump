#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> matrix(N, vector<int>(M));
    vector<vector<int>> sums(N + 1, vector<int>(M + 1, 0));
    for (size_t i = 0; i < N; i++){
        for (size_t j = 0; j < M; j++){
            cin >> matrix[i][j];
            if (i == 0 && j == 0)
                sums[i + 1][j + 1] = matrix[i][j];
            else if (i == 0)
                sums[i + 1][j + 1] = sums[i + 1][j] + matrix[i][j];
            else if (j == 0)
                sums[i + 1][j + 1] = sums[i][j + 1] + matrix[i][j];
            else
                sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
        }
    }
    for (size_t k = 0; k < K; k++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sums[x2][y2] - sums[x1 - 1][y2] - sums[x2][y1 - 1] + sums[x1 - 1][y1 - 1] << "\n";
    }
    return 0;
}
