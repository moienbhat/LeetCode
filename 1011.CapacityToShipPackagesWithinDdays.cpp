class Solution {
public:
    int findDays(vector<int>& weights, int cap) {
        int days = 1; 
        int load = 0;
        
        for (int w : weights) {
            if (load + w > cap) {
                days++;   
                load = w;    
            } else {
                load += w;   
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());  

        int high = accumulate(weights.begin(), weights.end(), 0); 

        while (low <= high) {
            int mid = (low + high) / 2;
            int requiredDays = findDays(weights, mid);
            
            if (requiredDays <= days) {
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }
        return low;
    }
};
