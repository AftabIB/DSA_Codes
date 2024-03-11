class Solution {
public:
    bool customComparator(char a,char b,string &s)
    {
        string compStr = s;
        return compStr.find(a) < compStr.find(b);
    }

    string customSortString(string order, string s) {
        // unordered_map<char,int> mp;
        // for(auto i:order)
        // {
        //     mp[order[i]]++;
        // }
        sort(s.begin(), s.end(), [&](char a, char b) {
            return customComparator(a, b, order);
        });
        return s;
    }
};