#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StackOfMins {
private:
    int* mins;
    size_t current_size;
public:
    StackOfMins(size_t size);

    void push(int x);

    void pop();

    int getMin();
};

StackOfMins::StackOfMins(size_t size) {
    current_size = 0;
    mins = new int[size];
}

void StackOfMins::push(int x) {
    if (current_size == 0)
        mins[current_size++] = x;
    else {
        size_t pos = current_size - 1;
        mins[current_size++] = min(x, mins[pos]);
    }
}

void StackOfMins::pop() {
    current_size--;
}

int StackOfMins::getMin() {
    return mins[current_size - 1];
}

int main() {
    size_t n;
    scanf("%d",&n);
    StackOfMins s(n);
    while(n--){
        int16_t op;
        scanf("%d",&op);
        if (op == 1){
            int x;
            scanf("%d",&x);
            s.push(x);
        }
        else if (op == 2)
            s.pop();
        else
            printf("%d\n", s.getMin());
    }
    return 0;
}
