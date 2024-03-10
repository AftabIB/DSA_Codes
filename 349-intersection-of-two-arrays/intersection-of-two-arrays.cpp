class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1 (nums1.begin(),nums1.end());
        set<int> s2 (nums2.begin(),nums2.end());

        unordered_map<int,int> mp;

        vector<int> ans;
        for(auto i: s1)
            mp[i]++;
        
        for(auto i: s2)
            mp[i]++;

        for(auto i: mp)
            if(i.second >= 2)
            {
                ans.push_back(i.first);
            }
        
        return ans;
    }
};