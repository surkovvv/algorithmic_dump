#include <iostream>
#include <string>
using namespace std;

int main() {
    string base;
    cin >> base;
    size_t size = base.size();
    for (size_t i = 0; i < size - 1; i++){
        cout << base[i];
        if (i < (size - 1) / 2)
            cout << "(";
        else if (i >= size / 2)
            cout << ")";
    }
    cout << base[size - 1];
    return 0;
}
