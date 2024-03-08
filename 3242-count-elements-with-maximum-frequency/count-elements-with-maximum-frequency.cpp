class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;

        //count the freq and store it to mp
        for(auto &freq : nums)
        {
            mp[freq]++;
        }  

        int cnt = 0;
        int maxFreq = INT_MIN;


        //counting max freq of elements and updating the maxFreq
        for(auto &i : mp)
        {
            if(i.second > maxFreq)
            {
                maxFreq = i.second;
            }
        }

        //counting total freq of all elements having same or max freq
        for(auto &i : mp)
        {
            if(i.second == maxFreq)
            {
                cnt += maxFreq;
            }
        }

        return cnt;
    }
};