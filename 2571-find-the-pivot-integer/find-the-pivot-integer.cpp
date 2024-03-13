class Solution {
public:
    int pivotInteger(int n) {
        n = (long long)n;
        long long totalSum = n*(n+1)/2;
        long long leftSum = 0;
        for(int i=1;i<=n;i++)
        {
            leftSum += i;
            if(leftSum == totalSum)
            {
                return i;
            }
            totalSum -= i;
        }
        return -1;

    }
};