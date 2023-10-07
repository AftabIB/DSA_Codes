class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;

        // Count occurrences of each character
        for (char ch : s) {
            count[ch]++;
        }

        // Find the first non-repeating character
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i]] == 1) {
                return i;
            }
        }

        return -1;  // Return -1 if no unique character is found
    }
};
