#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> v(N + 1);
    v[1] = 2;
    v[2] = 3;
    for (int i = 3; i <= N; i++){
        v[i] = v[i - 1] + v[i - 2];
    }
    cout << v[N];
    return 0;
}
