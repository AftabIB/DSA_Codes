// brute force
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int> st;
//         for(int i=0;i<nums.size();i++)
//         {
//             st.insert(nums[i]);
//         }

//         int k = st.size();
//         int j = 0;
//         for(int x:st)
//         {
//             nums[j++] = x;
//         }

//         return k;
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] != nums[i-1])
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};