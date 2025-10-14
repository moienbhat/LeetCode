#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap;
        stack<int> st;

        for(int num : nums2) {
            while(!st.empty() && st.top() < num) {
                ngeMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        for(int& num : nums1) {
            num = ngeMap.count(num) ? ngeMap[num] : -1;
        }

        return nums1;
    }
};
