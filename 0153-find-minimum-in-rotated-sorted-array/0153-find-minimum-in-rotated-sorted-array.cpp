class Solution {
public:
    int findMin(vector<int>& nums) {
        int m=INT_MAX;
        for(int i =0; i<nums.size();i++){
            if(nums[i]<m){
                m = nums[i];
            }
        }
        return m;
    }
};