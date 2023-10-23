class Solution {
public:
    bool isPowerOfFour(int n) {
         for(int i=0; i<=30; i++ )
        {
            long long answer = pow(4,i);
            if(answer == n)
            {
                return true;
            }
        }
        return false;
    }
};