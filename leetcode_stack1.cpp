#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> preferences;
        stack<int> sandwich;
        int number_of[2] = {0, 0};
        size_t n = students.size();
        for (size_t i = 0; i < n; i++){
            preferences.push(students[i]);
            sandwich.push(sandwiches[n - i - 1]);
            if (students[i] == 0)
                number_of[0]++;
            else
                number_of[1]++;
        }
        while (!sandwich.empty()){
            int pref = preferences.front();
            int sand = sandwich.top();
            if (sand == 0 && number_of[0] == 0)
                break;
            if (sand == 1 && number_of[1] == 0)
                break;
            if (pref == sand){
                preferences.pop();
                sandwich.pop();
                number_of[pref]--;
            }
            else {
                preferences.pop();
                preferences.push(pref);
            }
        }
        return sandwich.size();
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {1, 1, 1, 0, 0, 1}, v2 = {1, 0, 0, 0, 1, 1};
    std::cout << sol.countStudents(v1, v2) << std::endl;
    return 0;
}
