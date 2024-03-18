class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v1,v2;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]>0)
                v1.push_back(nums[i]);
            else 
                v2.push_back(nums[i]);
        }


        for(int i=0;i<nums.size()/2;i++)
        {
            nums[2*i] = v1[i];
            nums[2*i+1] = v2[i];
        }

        // int ind1=0,ind2=0;

        // while(ind2<nums.size()/2){
        //     ans.push_back(v1[ind1]);
        //     ind1++;
        //     ans.push_back(v2[ind2]);
        //     ind2++;
        // }

        return nums;
    }
};

