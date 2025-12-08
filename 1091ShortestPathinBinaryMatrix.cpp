class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1; // no possible path

        // Directions: 8 possible moves
        int drow[8] = {-1,-1,-1,0,1,1,1,0};
        int dcol[8] = {-1,0,1,1,1,0,-1,-1};

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;  // distance (we reuse grid to store distance)

        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            // If we reached bottom-right, return distance
            if(r == n-1 && c == n-1)
                return grid[r][c];

            // explore all 8 directions
            for(int i = 0; i < 8; i++) {

                int nr = r + drow[i];
                int nc = c + dcol[i];

                // check boundaries + must be 0 (clear path)
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1; // no path found
    }
};
