#include <iostream>
#include <vector>
using namespace std;

void print_arr(vector<int> array){
    for (auto i : array)
        cout << i;
    cout << endl;
}

void print_all_bin_strings(int k, vector<int> array){
    if (k == array.size()){
        print_arr(array);
        array[k - 1] = 1;
        print_arr(array);
        return;
    }
    print_all_bin_strings(k + 1, array);
    array[k - 1] = 1;
    print_all_bin_strings(k + 1, array);
}

int main() {
    int N;
    cin >> N;
    vector<int> bin_str(N, 0);
    print_all_bin_strings(1, bin_str);

    return 0;
}
