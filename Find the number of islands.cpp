#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to perform DFS and mark visited cells
    void dfs(vector<vector<char>>& grid, int row, int col, int n, int m) {
        // Check for boundary conditions and if the cell is water or already visited
        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == '0')
            return;

        // Mark the current cell as visited (turn it to water)
        grid[row][col] = '0';

        // Check all 8 directions: horizontal, vertical, and diagonal
        dfs(grid, row + 1, col, n, m);     // down
        dfs(grid, row - 1, col, n, m);     // up
        dfs(grid, row, col + 1, n, m);     // right
        dfs(grid, row, col - 1, n, m);     // left
        dfs(grid, row + 1, col + 1, n, m); // bottom-right diagonal
        dfs(grid, row + 1, col - 1, n, m); // bottom-left diagonal
        dfs(grid, row - 1, col + 1, n, m); // top-right diagonal
        dfs(grid, row - 1, col - 1, n, m); // top-left diagonal
    }

    // Function to find the number of islands
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of columns
        int count = 0;              // number of islands

        // Traverse through all cells in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the current cell is land ('1'), start a DFS
                if (grid[i][j] == '1') {
                    count++; // Increment the island count
                    dfs(grid, i, j, n, m); // Perform DFS to mark the entire island
                }
            }
        }

        return count; // Return the total number of islands
    }
};

int main() {
    Solution solution;
    
    // Example grid input for testing
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    // Call the function and print the result
    int result = solution.numIslands(grid);
    cout << "Number of islands: " << result << endl;
    
    return 0;
}
