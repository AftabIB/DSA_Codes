class Solution {
public:
    bool solve(int n,int k,vector<int>& nums)
    {
        vector<bool> prev(k+1,false), curr(k+1,false);
        prev[0] = curr[0] = true;
        // prev[nums[0]] = true;

        for(int index=1;index<n;index++)
        {
            for(int target=1;target<=k;target++)
            {
                bool noTake = prev[target];
                bool take = false;
                if(target >= nums[index])
                {
                    take = prev[target-nums[index]];
                }
                curr[target] = take || noTake;
            }
            prev = curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return 0;
        int totalSum = 0;
        
        for(int i=0;i<n;i++)
            totalSum += nums[i];
        
        if(totalSum % 2)
            return false;

        int target = totalSum/2;

        return solve(n,target,nums);
    }
};