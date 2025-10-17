class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, h = n-1;
       for(int i = 0; i<nums.size(); i++){
        int mid = (l+h)/2;
        if(nums[i] == target){
            return i;
        }
        else if(nums[i]>mid){
            l = mid+1;
        }
        else h = mid-1;
       }
       return -1; 
    }
};