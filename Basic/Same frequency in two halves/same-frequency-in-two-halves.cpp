//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    bool passed (string s) {
        //code here.
        if(s.length() % 2 != 0)
            s.erase(s.begin() + s.length() / 2);
        
        string str1 = "";
        string str2 = "";
        for(int i=0;i<s.length()/2;i++)
        {
            str1 += s[i];
        }
        
        for(int i = s.length()-1;i>=s.length()/2;i--)
        {
            str2 += s[i];
        }
        
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        
        if(str1 == str2)
            return 1;
        else
            return 0;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        if (ob.passed (s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
// } Driver Code Ends