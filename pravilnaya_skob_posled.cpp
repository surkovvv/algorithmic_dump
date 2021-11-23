#include <iostream>
#include <stack>
using namespace std;

int main() {
    char skobka;
    stack<char> skobki;
    bool result = true;
    while (cin >> skobka){
        if (skobka == ')'){
            if (skobki.empty() || skobki.top() != '('){
                result = false;
                break;
            }
            skobki.pop();
        }
        else if (skobka == '}'){
            if (skobki.empty() || skobki.top() != '{'){
                result = false;
                break;
            }
            skobki.pop();
        }
        else if (skobka == ']'){
            if (skobki.empty() || skobki.top() != '['){
                result = false;
                break;
            }
            skobki.pop();
        }
        else
            skobki.push(skobka);
    }
    if (result && skobki.empty())
        cout << "yes";
    else
        cout << "no";
    return 0;
}
