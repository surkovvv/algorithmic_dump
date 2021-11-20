#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    size_t N;
    cin >> N;
    vector<int> numbers(N);
    for (size_t i = 0; i < N; i++)
        cin >> numbers[i];
    vector<size_t> dp(N, 1);
    size_t answer = 1;
    for (size_t i = 1; i < N; i++){
        int j = i - 1;
        while (j >= 0){
            if (dp[j] + 1 > dp[i] && numbers[j] < numbers[i]) {
                dp[i] = dp[j] + 1;
            }
            j--;
        }
        if (dp[i] > answer)
            answer = dp[i];
    }
    cout << answer;
    return 0;
}
