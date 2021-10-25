#include <iostream>
#include <cmath>
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
    int x0, x, y0, y;
    cin >> x0 >> y0 >> x >> y;
    int X = abs(x - x0), Y = abs(y - y0);
    if (X == 0 || Y == 0)
        cout << 0;
    else
        cout << X + Y - gcd(X, Y);
    return 0;
}
