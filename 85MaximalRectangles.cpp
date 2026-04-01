class Solution {
private:

    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        int largestArea = 0;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int ind = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                int area = heights[ind] * (nse - pse - 1);
                largestArea = max(largestArea, area);
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            int ind = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = n;
            int area = heights[ind] * (nse - pse - 1);
            largestArea = max(largestArea, area);
        }
        
        return largestArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> heights(n, vector<int>(m, 0));
        

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = (i == 0) ? 1 : heights[i - 1][j] + 1;
                } else {
                    heights[i][j] = 0;
                }
            }
        }
        
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, largestRectangleArea(heights[i]));
        }
        
        return maxArea;
    }
};
