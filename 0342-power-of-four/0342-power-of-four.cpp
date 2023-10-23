class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
        {
            return true;
        }
        
        long long x = 4;
        while(x<=n)
        {
            if(x==n)    return true;
            x *= 4;
        }
        return false;
    }
};