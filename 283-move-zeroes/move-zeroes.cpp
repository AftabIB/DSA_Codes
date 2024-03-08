class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int n = nums.size();
        int left = 0; // Pointer to keep track of the current position to place non-zero elements

        // Iterate through the array
        for (int right = 0; right < n; right++) {
            // If the current element is non-zero, move it to the left pointer position
            if (nums[right] != 0) {
                nums[left++] = nums[right];
            }
        }

        // Fill the remaining positions with zeros
        while (left < n) {
            nums[left++] = 0;
        }
    }
};