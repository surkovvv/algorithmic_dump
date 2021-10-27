#include <iostream>
#include <vector>
using namespace std;
int N;

void print_arr(const vector<int>& array){
    for (auto i : array)
        cout << i;
    cout << endl;
}

void print_all_bin_strings_with_n_ones(int k, int cur_sum, vector<int> array){
    if (k == array.size()){
        if (cur_sum == N)
            print_arr(array);
        array[k - 1] = 1;
        if (cur_sum + 1 == N)
            print_arr(array);
        return;
    }
    print_all_bin_strings_with_n_ones(k + 1, cur_sum, array);
    array[k - 1] = 1;
    print_all_bin_strings_with_n_ones(k + 1, cur_sum + 1, array);
}

int main() {
    int n;
    cin >> n >> N;
    vector<int> bin_str(n, 0);
    print_all_bin_strings_with_n_ones(1, 0, bin_str);
    return 0;
}
