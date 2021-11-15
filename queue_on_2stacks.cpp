#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class QueueOn2Stacks {
private:
    stack<T> s1, s2;
public:
    void push(T x){
        s2.push(x);
        cout << "ok\n";
    }
    void pop() {
        if (s2.empty() && s1.empty()) {
            cout << "error\n";
            return;
        }
        if (s1.empty()){
            while (!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        cout << s1.top() << "\n";
        s1.pop();
    }

    void front() {
        if (s2.empty() && s1.empty()) {
            cout << "error\n";
            return;
        }
        if (s1.empty()){
            while (!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        cout << s1.top() << "\n";
    }

    size_t size() {
        return s1.size() + s2.size();
    }

    void clear(){
        while (!s1.empty())
            s1.pop();
        while (!s2.empty())
            s2.pop();
        cout << "ok\n";
    }
};

int main() {
    string command;
    int number;
    QueueOn2Stacks<int> test;
    while (cin >> command && command != "exit"){
        if (command == "push"){
            cin >> number;
            test.push(number);
        }
        else if (command == "pop")
            test.pop();
        else if (command == "front")
            test.front();
        else if (command == "size")
            cout << test.size() << "\n";
    }
    cout << "bye";
    return 0;
}
