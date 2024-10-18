class Solution {
public:
    static int countMaxOrSubsets(vector<int>& nums) {
        const unsigned n=nums.size(), bmask=(1<<n)-1;
        int cnt=0, max_OR;
        for (int mask=1; mask<=bmask; mask++){
            unsigned acc_or=0;
            for(int i=0; i<n; i++){
                if ( (mask>>i)& 1) acc_or|=nums[i];
            }
            if (acc_or>max_OR) max_OR=acc_or, cnt=1;
            else if (acc_or==max_OR) cnt++;
        }
        return cnt;
    }
};