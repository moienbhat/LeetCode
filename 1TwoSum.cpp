class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> numsWithIndex;
        for(int i=0; i<n; i++){
            numsWithIndex.push_back({nums[i], i});
        }
        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0, right = n-1;

        while(left<right){
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if(sum == target){
                return {numsWithIndex[left].second, numsWithIndex[right].second};
            }
            else if(sum < target) left++;
            else right--;

        }
        return{-1, -1};

    }
};