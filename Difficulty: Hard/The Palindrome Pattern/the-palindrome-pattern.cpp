//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        int flag1 = 1;
        for (int j = 0; j < n / 2; j++) {
            if (arr[i][j] != arr[i][n - j - 1]) {
                flag1 = 0;
                break;
            }
        }
        if (flag1 == 1) {
            return to_string(i) + " R";
        }
    }
        for (int i = 0; i < n; i++) {

        int flag2 = 1;
        for (int j = 0; j < n / 2; j++) {
            if (arr[j][i] != arr[n - j - 1][i]) {
                flag2 = 0;
                break;
            }
        }
        if (flag2 == 1) {
            return to_string(i) + " C";
        }
    }

    return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends