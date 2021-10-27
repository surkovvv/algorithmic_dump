#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> first, second, third;
vector<stack<int>> stacks;

void shift_n_disks_to(int n, int from, int to){
    if (n == 1){
         cout << stacks[from - 1].top() << " " << from << " " << to << "\n";
         stacks[to - 1].push(stacks[from - 1].top());
         stacks[from - 1].pop();
         return;
    }
    int free;
    if (from == 1) free = (to == 2 ? 3 : 2);
    else if (from == 2) free = (to == 1 ? 3 : 1);
    else free = (to == 1 ? 2 : 1);
    shift_n_disks_to(n - 1, from, free);
    cout << n << " " << from << " " << to << '\n';
    stacks[to - 1].push(stacks[from - 1].top());
    stacks[from - 1].pop();
    shift_n_disks_to(n - 1, free, to);
}

int main() {
    int n, from, to;
    cin >> n;
    stacks.push_back({});
    stacks.push_back({});
    stacks.push_back({});
    for (int i = n; i > 0; i--){
        stacks[0].push(i);
    }
    //stacks = {first, second, third};
    shift_n_disks_to(n, 1, 3);
    return 0;
}
