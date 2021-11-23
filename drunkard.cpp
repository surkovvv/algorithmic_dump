#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int16_t> first, second;
    for (size_t i = 0; i < 5; i++){
        int16_t number;
        cin >> number;
        first.push(number);
    }
    for (size_t i = 0; i < 5; i++){
        int16_t number;
        cin >> number;
        second.push(number);
    }
    size_t counter = 0;
    while (!first.empty() && !second.empty()){
        int16_t first_player_card = first.front();
        int16_t second_player_card = second.front();
        first.pop();
        second.pop();
        if (first_player_card == 0 && second_player_card == 9){
            first.push(first_player_card);
            first.push(second_player_card);
        }
        else if (first_player_card == 9 && second_player_card == 0) {
            second.push(first_player_card);
            second.push(second_player_card);
        }
        else if (first_player_card > second_player_card){
            first.push(first_player_card);
            first.push(second_player_card);
        }
        else {
            second.push(first_player_card);
            second.push(second_player_card);
        }
        counter ++;
        if (counter == 10e5){
            cout << "botva";
            break;
        }
    }
    if (first.empty())
        cout << "second " << counter;
    else if (second.empty())
        cout << "first " << counter;
    return 0;
}
