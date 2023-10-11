class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> s,e;
        for(auto j: flowers)
        {
            s.push_back(j[0]),e.push_back(j[1]);
        }

        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        vector<int> ans;
        for(auto j: people)
        {
            auto a = upper_bound(s.begin(),s.end(),j);
            auto b = lower_bound(e.begin(),e.end(),j);
            int c = a-s.begin();
            int d = b-e.begin();
            ans.push_back(c-d);
        }
        return ans;
    }
};