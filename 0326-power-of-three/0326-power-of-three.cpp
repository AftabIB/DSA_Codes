class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)
        {
            return false;
        }
        else if(n==1)
        {
            return true;
        }
        long long x = 3;
        while(x<=n)
        {
            if(x==n)    return true;
            x *= 3;
        }
        return false;
    }
};