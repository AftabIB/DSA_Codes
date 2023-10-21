class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false; // 1 is not a perfect number
        }
        
        int sum = 1; // Start with 1 because all numbers are divisible by 1
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    sum += num / i;
                }
            }
        }
        
        return sum == num;
    }
};
