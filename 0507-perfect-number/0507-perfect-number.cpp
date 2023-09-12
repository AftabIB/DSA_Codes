class Solution {
public:
    bool checkPerfectNumber(int num) {
        // code here
        if(num==1)return 0;
        long long sum=1;
        for(long long i=2;i<=sqrt(num);i++){
            if(num%i==0){
                sum+=i;
                sum+=(num/i);
            }
        }
        if(sum==num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};