#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> stack;
    size_t size_;
public:
    Stack() : stack({}), size_(0) {};
    Stack(size_t n) : stack(vector<T>(n)), size_(n) {};
    void push(T x){
        stack.push_back(x);
        size_++;
        cout << "ok\n";
    }
    void pop() {
        cout << stack[size_ - 1] << "\n";
        stack.pop_back();
        size_--;
    }

    void size(){
        cout << size_ << '\n';
    }

    void back(){
        cout << stack[size_ - 1] << "\n";
    }

    void clear() {
        stack.clear();
        size_ = 0;
        cout << "ok\n";
    }

};

int main() {
    string command;
    int number;
    Stack<int> test;
    while (cin >> command && command != "exit"){
        if (command == "push") {
            cin >> number;
            test.push(number);
        }
        else if (command == "size")
            test.size();
        else if (command == "clear")
            test.clear();
        else if (command == "pop")
            test.pop();
        else
            test.back();
    }
    cout << "bye";
    return 0;
}
