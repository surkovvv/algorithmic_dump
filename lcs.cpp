#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a;
    cin >> b;
    size_t n = a.size(), m = b.size();
    vector<vector<size_t>> dp(n + 1, vector<size_t>(m + 1, 0));
    for (size_t i = 1; i <= n; i++){
        for (size_t j = 1; j <= m; j++){
            size_t diag = (a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1 : 0);
            dp[i][j] = max(diag, max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    cout << dp[n][m] << "\n";
    /*for (size_t i = 1; i <= n; i++){
        for (size_t j = 1; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }*/

    vector<int> seq1;
    vector<int> seq2;

    while(n > 0 && m > 0) {
        if(a[n - 1] == b[m - 1]) {
            seq1.push_back(n - 1);
            seq2.push_back(m - 1);
            n--;
            m--;
        }
        else {
            if(dp[n - 1][m] == dp[n][m]) {
                n--;
            }
            else if(dp[n][m - 1] == dp[n][m]) {
                m--;
            }
        }
    }

    reverse(seq1.begin(), seq1.end());
    reverse(seq2.begin(), seq2.end());

    for(auto i : seq1) {
        cout << i + 1 << " ";
    }
    cout << "\n";
    for(auto i : seq2) {
        cout << i + 1 << " ";
    }

    return 0;
}
