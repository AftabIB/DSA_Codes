//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) 
    {
        long long num=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0')
            {
                if(s[i]<'9')    num=num*10+(s[i]-'0');
                else if(s[i]=='9')
                {
                    while(s[i]!=' ' && i<s.size()) i++;
                    num=0;
                }
            }
            if(s[i]==' ' || i==s.size()-1)
            {
                if(num) ans=max(ans,num);
                num=0;
            }
        }
        return ans?ans:-1;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends