//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int lowerNibble = 0, upperNibble = 0;
        lowerNibble = n & 15;
        upperNibble = n & 240;
        lowerNibble <<= 4;
        upperNibble >>= 4;
        return lowerNibble | upperNibble;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends