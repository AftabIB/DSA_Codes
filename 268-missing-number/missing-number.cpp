#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int xor1 = 0;
        int n = nums.size();
        
        // XOR of numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xor1 ^= i;
        }
        
        // XOR of all elements in nums
        for (int num : nums) {
            xor1 ^= num;
        }

        return xor1;
    }
};
