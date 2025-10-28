class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int m = INT_MIN;
        int maxI = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] >= m){
                m= nums[i];
                maxI = i;
            }
        }
        return maxI;
    }
};