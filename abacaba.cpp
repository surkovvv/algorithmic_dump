#include <iostream>
#include <string>
using namespace std;
char A[6] = {'B', 'C', 'D', 'E', 'F'};


string make_string(string& base, int number){
    for (int k = 0; k < number - 1; k++){
        base = base + A[k] + base;
    }
    return base;
}

int main() {
    int n;
    cin >> n;
    string base = "A";
    cout << make_string(base, n);
    return 0;
}
