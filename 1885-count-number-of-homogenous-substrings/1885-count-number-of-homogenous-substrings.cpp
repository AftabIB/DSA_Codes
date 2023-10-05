
class Solution {
public:
    int countHomogenous(string s) {
        
        if(s.length()==1) return 1;
        long long count=0;
        long long ans=0;
        int n=s.length();
        int i=0;
        for(;i<n-1;i++){
            while(s[i]==s[i+1]&&i<n-1){
                count++;
                i++;
            }
            count++;
            ans+=(((count+1)*count)/2)%1000000007;
            count=0;
        }
        if(i==n-1){
            count++;
            ans+=((count+1)*count)/2;
        }
        return ans;
    }
};