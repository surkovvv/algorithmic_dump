#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    // хочу пихать + nums[i] и вызываться рекурсивно со след элемента
    // и потом пихать - nums[i] и так же вызываться рекурсивно
    // как только i == nums.size() (а начинаем с i = 0) - считаем сумму по всем элементам стека
    // было бы круто хранить в вызовах еще и сумму, и просто на последнем этапе возвращать
    // sum + nums[nums.size() - 1] == target?
    // или просто если условие выше выполнено - ++ к подсчетной переменной
    void myFoo(size_t i, int sum){
        if (i == nums_.size()){
            if (sum == target_)
                n_ways++;
            return;
        }
        myFoo(i + 1, sum + nums_[i]);
        myFoo(i + 1, sum - nums_[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        nums_ = nums;
        target_ = target;
        myFoo(0, 0);
        return n_ways;
    }
private:
    vector<int> nums_;
    int target_;
    int n_ways = 0;
};


int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    Solution solution;
    cout << solution.findTargetSumWays(nums, 3);
    return 0;
}
