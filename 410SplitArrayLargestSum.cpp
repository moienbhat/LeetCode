class Solution {
public:
    int countPartitions(vector<int>& nums, int maxSum) {
        int partitions = 1;
        long long subarraySum = 0;
        
        for (int x : nums) {
            if (subarraySum + x <= maxSum) {
                subarraySum += x;
            } else {
                partitions++;
                subarraySum = x;
            }
        }
        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());   // minimum possible largest sum
        int high = accumulate(nums.begin(), nums.end(), 0); // maximum possible largest sum
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int partitions = countPartitions(nums, mid);
            
            if (partitions > k) {
                low = mid + 1;   // need larger sum
            } else {
                high = mid - 1;  // can try smaller sum
            }
        }
        return low;
    }
};
