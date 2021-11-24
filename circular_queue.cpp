#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        buffer = vector<int>(k);
        size_ = k;
        front = 0;
        back = 0;
        current_size = 0;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;
        else {
            buffer[back] = value;
            back = (back + 1) % size_;
            current_size++;
            return true;
        }
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        else {
            front = (front + 1) % size_;
            current_size--;
            return true;
        }
    }

    int Front() {
        if (isEmpty())
            return -1;
        else
            return buffer[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        else
            return buffer[(back == 0 ? size_ - 1 : back - 1)];
    }

    bool isEmpty() {
        return current_size == 0;
    }

    bool isFull() {
        return current_size == size_;
    }
private:
    vector<int> buffer;
    size_t front, back, size_, current_size;
};

/* Your MyCircularQueue object will be instantiated and called as such:
MyCircularQueue* obj = new MyCircularQueue(k);
bool param_1 = obj->enQueue(value);
bool param_2 = obj->deQueue();
int param_3 = obj->Front();
int param_4 = obj->Rear();
bool param_5 = obj->isEmpty();
bool param_6 = obj->isFull();
*/


int main() {
    MyCircularQueue* obj = new MyCircularQueue(3);
    obj->enQueue(7);
    obj->deQueue();
    obj->Front();
    obj->deQueue();
    obj->Front();
    obj->Rear();
    obj->enQueue(0);
    obj->isFull();
    obj->deQueue();
    obj->Rear();
    obj->enQueue(3);
    return 0;
}
