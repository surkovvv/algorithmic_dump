#include <iostream>
using namespace std;

int gcd(int a, int b){
    while (a && b){
        if (a == 1 || b == 1)
            return 1;
        if (abs(a) < b)
            b = b % a;
        else
            a = a % b;
    }
    return max(abs(a), b);
}

int main() {
    int numerator, denominator;
    cin >> numerator >> denominator;
    int GCD = gcd(numerator, denominator);
    //cout << GCD << "\n";
    cout << numerator / GCD << " " << denominator / GCD;
    return 0;
}
