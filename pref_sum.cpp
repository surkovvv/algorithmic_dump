#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int* arr = new int[N];
    int *pref_sum = new int[N + 1];
    pref_sum[0] = 0;
    for (size_t i = 0; i < N; i++){
        cin >> arr[i];
        pref_sum[i + 1] = pref_sum[i] + arr[i];
    }
    for (size_t j = 0; j < M; j++){
        int l, r;
        cin >> l >> r;
        cout << pref_sum[r] - pref_sum[l - 1] << "\n";
    }
    return 0;
}
