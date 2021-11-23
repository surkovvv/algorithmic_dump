#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        size_t time = 0;
        size_t index = 0;
        while (tickets[k] > 0){
            if (tickets[index] == 0) {
                index++;
                index %= tickets.size();
                continue;
            }
            else
                tickets[index]--;
            index++;
            index %= tickets.size();
            time++;
        }
        return time;
    }
};

int main() {
    Solution sol;
    vector<int> v = {5, 1, 1, 1};
    std::cout << sol.timeRequiredToBuy(v, 0) << std::endl;
    return 0;
}
