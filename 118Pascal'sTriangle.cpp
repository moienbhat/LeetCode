class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        if (numRows == 0) return ans;

        // First row
        ans.push_back({1});

        // Generate remaining rows
        for (int i = 1; i < numRows; i++) {
            vector<int> row;

            // First element
            row.push_back(1);

            // Previous row
            vector<int>& prev = ans[i - 1];

            // Middle elements
            for (int j = 1; j < i; j++) {
                row.push_back(prev[j - 1] + prev[j]);
            }

            // Last element
            row.push_back(1);

            ans.push_back(row);
        }

        return ans;
    }
};
