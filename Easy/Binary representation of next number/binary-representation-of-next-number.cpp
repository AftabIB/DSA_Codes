//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        string res = s;
        
        int n = res.length();
        
        int i = n - 1;
        
        while(i >= 0)
        {
            if(res[i] == '0')
            {
                res[i] = '1';
                break;
            }
            
            res[i] = '0';
            
            i--;
        }
        
        if(i < 0)
        {
            res = '1' + res;
        }
        
        i = 0;
        
        while(res[i] == '0')
        {
            
            res.erase(res.begin());
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends