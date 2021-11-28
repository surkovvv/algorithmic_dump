#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
    // Решение : каждый код - и есть вершина графа, их всего 10000
    // между 2 вершинами есть ребро, если они отличаются ровно в 1 символе на соседний символ
    // у каждой вершины есть 8 соседей
public:
    int openLock(vector<string>& deadends, const string& target) {
        unordered_set<string> graph;
        unordered_set<string> deads(deadends.begin(), deadends.end());
        size_t number = 0;
        queue<string> all_codes;
        if ("0000" == target)
            return number;
        if (deads.find("0000") != deads.end())
            return -1;
        all_codes.push("0000");
        while (!all_codes.empty()){
            size_t queue_size = all_codes.size();
            //cout << "Step " << number << " with " << queue_size << " in queue\n";
            for (size_t i = 0; i < queue_size; i++){
                string code = all_codes.front();
                all_codes.pop();
                for (size_t j = 0; j < 4; j++){
                    string less = code, more = code;
                    char digit = code[j];
                    //cout << digit << '\n';
                    less[j] = (code[j] == '0') ? '9' : (digit - 1);
                    more[j] = (code[j] == '9') ? '0' : (digit + 1);
                    //cout << less << " " << more << "\n";
                    if (less == target || more == target)
                        return ++number;
                    if (deads.find(less) == deads.end() && graph.find(less) == graph.end()) {
                        all_codes.push(less);
                        graph.insert(less);
                    }
                    if (deads.find(more) == deads.end() && graph.find(more) == graph.end()) {
                        all_codes.push(more);
                        graph.insert(more);
                    }
                }
            }
            number++;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<string> v = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target = "8888";
    cout << sol.openLock(v, target);
    //char symb = target[0] + 1;
    //cout << symb;
    return 0;
}
