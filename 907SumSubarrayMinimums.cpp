class Solution {
private:
    // Next Smaller Element (NSE)
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }

        return ans;
    }

    // Previous Smaller or Equal Element (PSEE)
    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }

        return ans;
    }

public:
    int SumSubArrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int n = arr.size();
        int mod = 1e9 + 7;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;

            long long freq = 1LL * left * right;
            long long val = (freq * arr[i]) % mod;

            sum = (sum + val) % mod;
        }

        return sum;
    }
};