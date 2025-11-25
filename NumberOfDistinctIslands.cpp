#include<iostream>
#include<vector>
#include<queue>



using namespace std;

class Solution {
public:
    // Function to perform BFS traversal
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        // Create a queue to store coordinates
        queue<pair<int, int>> q;
        // Push starting cell to queue
        q.push({row, col});
        // Mark the cell as visited
        vis[row][col] = 1;

        // Define all 8 directions
        int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delCol[] = {-1,  0,  1, 1, 1, 0, -1, -1};

        // Loop while queue is not empty
        while (!q.empty()) {
            // Get front cell from queue
            int r = q.front().first;
            int c = q.front().second;
            // Pop it from the queue
            q.pop();

            // Traverse all 8 directions
            for (int i = 0; i < 8; i++) {
                // Calculate new row and column
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                // Check bounds and unvisited land
                if (nrow >= 0 && nrow < grid.size() &&
                    ncol >= 0 && ncol < grid[0].size() &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    
                    // Mark as visited and push to queue
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    // Function to count number of islands
    int numIslands(vector<vector<char>>& grid) {
        // Get grid dimensions
        int n = grid.size();
        int m = grid[0].size();

        // Create visited matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Counter for islands
        int count = 0;

        // Loop through entire grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If cell is unvisited land
                if (!vis[i][j] && grid[i][j] == '1') {
                    // Increment island count
                    count++;
                    // Call BFS
                    bfs(i, j, vis, grid);
                }
            }
        }

        // Return total islands
        return count;
    }
};

// Driver code
int main() {
    // Create grid
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    // Create Solution object
    Solution obj;
    // Call function and print result
    cout << obj.numIslands(grid) << endl;
    return 0;
}