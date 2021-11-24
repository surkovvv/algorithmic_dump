#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        size_t m = grid.size(), n = grid[0].size(), number_of_islands = 0;
        stack<pair<int, int>> indices;
        for (size_t i = 0; i < m; i++){
            for (size_t j = 0; j < n; j++){
                if (grid[i][j] == '1'){
                    number_of_islands++;
                    indices.push({i, j});
                    while (!indices.empty()){
                        int row = indices.top().first;
                        int col = indices.top().second;
                        grid[row][col] = '0';
                        indices.pop();

                        if (row + 1 < m && grid[row + 1][col] == '1')
                            indices.push({row + 1, col});
                        if (row - 1 >= 0 && grid[row - 1][col] == '1')
                            indices.push({row - 1, col});
                        if (col + 1 < n && grid[row][col + 1] == '1')
                            indices.push({row, col + 1});
                        if (col - 1 >= 0 && grid[row][col - 1] == '1')
                            indices.push({row, col - 1});
                    }
                }
            }
        }

        return number_of_islands;
    }
};

int main() {
    vector<vector<char>> grid = {{'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '1'}};
    Solution sol;
    std::cout << sol.numIslands(grid) << std::endl;
    return 0;
}
