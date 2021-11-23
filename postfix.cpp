#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    char symbol;
    stack<int> results;
    while (cin >> symbol){
         if (symbol >= '0' && symbol <= '9') {
             results.push(symbol - '0');
         }
         else{
             int left, right;
             right = results.top();
             results.pop();
             left = results.top();
             results.pop();
             if (symbol == '+')
                results.push(left + right);
             else if (symbol == '-')
                 results.push(left - right);
             else if (symbol == '*')
                 results.push(left * right);
         }
    }
    cout << results.top();
    return 0;
}
