#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> mp;
        int n = candyType.size();
        
        for (int i = 0; i < n; ++i) {
            mp[candyType[i]]++;
        }
        
        if (mp.size() <= n / 2) {
            return mp.size();
        } else {
            return n / 2;
        }
    }
};
