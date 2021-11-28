#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
    // идея - каждое число - вершина, его соседи - все квадраты чисел, которые меньше его самого
    // например для n = 7 эти соседи есть 4, 1
    // итого : для каждой вершины добавляем в очередь все числа вида num - square
    int numSquares(int n) {
        vector<int> squares;
        int num = sqrt(n);
        while (num > 0){
            squares.push_back(num * num);
            num--;
        }
        size_t min_depth = 0;
        queue<int> new_num;
        new_num.push(n);
        while (!new_num.empty()) {
            size_t sz = new_num.size();
            for (size_t i = 0; i < sz; i++) {
                int num = new_num.front();
                new_num.pop();
                for (auto square : squares) {
                    //if (square < n / 2)
                    //    break; <-- нужно что то поумнее
                    if (num - square > 0) {
                        new_num.push(num - square);
                    } else if (num == square)
                        return ++min_depth;
                }
            }
            min_depth++;
        }
    }
};

int main() {
    Solution solution;
    cout << solution.numSquares(9) << "\n";
    return 0;
}
