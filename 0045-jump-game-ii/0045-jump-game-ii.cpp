class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n=nums.size();
        
        if(n==1)
        {
            return 0;
        }
        int coverage=0;
        int lastindex=0;
        int totaljump=0;
        for(int i=0;i<n;i++)
        {
            coverage=max(coverage,i+nums[i]);
            if(i==lastindex)
            {
                totaljump++;
                lastindex=coverage;
                if(coverage>=n-1)
                {
                    return totaljump;
                }
            }

            if(i>coverage)
            {
                return -1;
            }
        }    
        return totaljump;
    }
};