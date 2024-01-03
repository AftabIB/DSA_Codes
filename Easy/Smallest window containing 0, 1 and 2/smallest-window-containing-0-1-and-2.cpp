//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int smallestSubstring(string S) {
        int zero = -1, one = -1, two = -1, res = INT_MAX; // Using INT_MAX instead of 10001
        
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '0') zero = i;
            if (S[i] == '1') one = i;
            if (S[i] == '2') two = i;
            
            if (zero == -1 || one == -1 || two == -1) continue;
            
            int minIndex = min(min(one, two), zero);
            int maxIndex = max(max(one, two), zero);
            res = min(res, (maxIndex - minIndex + 1));
        }
        return (res == INT_MAX) ? -1 : res; // Return 0 if no substring found, else return res
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends