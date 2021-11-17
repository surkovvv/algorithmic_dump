#include <iostream>
#include <deque>
using namespace std;


int main() {
    deque<uint32_t> test;
    size_t ids[100001]; // для каждого айдишника храним порядок его добавления(исторический)
    // но если встречается команда 3, мы уменьшаем этот порядок на 1
    size_t n, order = 1, k = 0; // k - счетчик команд 2
    cin >> n;
    for (size_t i = 0; i < n; i++){
        uint16_t command_id;
        cin >> command_id;
        if (command_id == 1) {
            uint32_t person_id;
            cin >> person_id;
            test.push_back(person_id);
            ids[person_id] = order;
            order++;
        }
        else if (command_id == 2) {
            test.pop_front();
            k++;
        }
        else if (command_id == 3) {
            test.pop_back();
            order--;
        }
        else if (command_id == 4) {
            uint32_t id;
            cin >> id;
            cout << ids[id] - k - 1 << "\n";
        }
        else {
            cout << test.front() << "\n";
        }
    }
    return 0;
}
