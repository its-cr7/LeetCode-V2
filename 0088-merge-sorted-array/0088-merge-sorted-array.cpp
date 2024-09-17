class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n,0);
        int a = 0, i=0,j=0;
        while(i<m && j<n){
           if(nums1[i] <= nums2[j]){
                ans[a] = nums1[i];
                i++;
                a++;
           } 
           else if(nums1[i] > nums2[j]){
            ans[a] = nums2[j];
            j++;
            a++;
           }

        }
        while(i<m){
            ans[a] = nums1[i];
            i++;
            a++;
        }
        while(j<n){
            ans[a] = nums2[j];
            j++;
            a++;
        }
        nums1 = ans;
    }
};