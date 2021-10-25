#include <iostream>
using namespace std;

int gcd(int a, int b){
    while (a && b){
        if (a == 1 || b == 1)
            return 1;
        if (a < b)
            b = b % a;
        else
            a = a % b;
    }
    return max(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}
