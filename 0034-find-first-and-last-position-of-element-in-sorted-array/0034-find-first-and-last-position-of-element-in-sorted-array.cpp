class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = -1, lst =-1;
        int l=0, n=nums.size(), h=n-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m] == target){
                f=m;
                h = m-1;
            }
            else if(nums[m] < target){
                l=m+1;
            }
            else h=m-1;
        }
        l=0,h=n-1;
         while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m] == target){
                lst=m;
                l = m+1;
            }
            else if(nums[m] < target){
                l=m+1;
            }
            else h=m-1;
        }
        return {f,lst};
    }
};