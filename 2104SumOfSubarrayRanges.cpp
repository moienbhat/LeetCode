class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;


        stack<int> stMax;
        for (int i = 0; i <= n; i++) {
            while (!stMax.empty() && (i == n || nums[stMax.top()] < nums[i])) {
                int mid = stMax.top(); stMax.pop();
                int left = stMax.empty() ? -1 : stMax.top();
                int right = i;
                res += 1LL * nums[mid] * (mid - left) * (right - mid);
            }
            stMax.push(i);
        }


        stack<int> stMin;
        for (int i = 0; i <= n; i++) {
            while (!stMin.empty() && (i == n || nums[stMin.top()] > nums[i])) {
                int mid = stMin.top(); stMin.pop();
                int left = stMin.empty() ? -1 : stMin.top();
                int right = i;
                res -= 1LL * nums[mid] * (mid - left) * (right - mid);
            }
            stMin.push(i);
        }

        return res;
    }
};
