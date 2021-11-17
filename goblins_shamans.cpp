#include <iostream>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

struct LinkList {
    LinkList* next;
    int value;
    LinkList(int val) : value(val) {};
};

int main(){
// Идея: использовать связный список!(и хранить 3 указателя - на начало, середину, конец
// * вставляем после (size + 1) / 2
// добавляем в конец, сдвигаем
    LinkList* start, *mid, *end;
    size_t n, actual_size = 0;
    cin >> n;
    for (size_t i = 0; i < n; i++){
        char oper;
        int id;
        cin >> oper;
        if (oper == '+'){
            cin >> id;
            if (actual_size == 0){
                start = new LinkList(id);
                mid = start;
                end = start;
            }
            else if (actual_size == 1){
                end = new LinkList(id);
                mid->next = end;
                start->next = end;
            }
            else {
                auto *new_end = new LinkList(id);
                end->next = new_end;
                end = new_end;
                if ((actual_size + 1) / 2 != (actual_size + 2) / 2) // двигаем mid
                    mid = mid->next;
            }
            actual_size++;
        }
        else if (oper == '*'){
            cin >> id;
            if (actual_size == 0){
                start = new LinkList(id);
                mid = start;
                end = start;
            }
            else if (actual_size == 1){
                end = new LinkList(id);
                mid->next = end;
                start->next = end;
            }
            else {
                auto *to_add = new LinkList(id);
                to_add->next = mid->next;
                mid->next = to_add;
                if ((actual_size + 1) / 2 != (actual_size + 2) / 2) // двигаем mid
                    mid = mid->next;
            }
            actual_size++;
        }
        else {
            cout << start->value << "\n";
            start = start->next;
            actual_size--;
            if (actual_size % 2 == 1)
                mid = mid->next;
        }
    }
    return 0;
}
