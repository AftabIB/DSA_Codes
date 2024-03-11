class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        int n = order.length();

        for (int i = 0; i < n; i++) {
            mp[order[i]] = i;
        }

        auto customComparator = [&](char a, char b) {
            return mp[a] < mp[b];
        };
        
        sort(s.begin(), s.end(), customComparator);
        
        return s;
    }
};



// class Solution {
// public:
//     bool customComparator(char a,char b,string &s)
//     {
//         string compStr = s;
//         return compStr.find(a) < compStr.find(b);
//     }

//     string customSortString(string order, string s) {
//         sort(s.begin(), s.end(), [&](char a, char b) {
//             return customComparator(a, b, order);
//         });
//         return s;
//     }
// };