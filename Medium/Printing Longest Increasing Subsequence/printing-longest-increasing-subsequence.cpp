//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for (int index = 1; index < n; index++) { // Changed from 0 to 1 to start from the second element
        hash[index] = index;
        for (int prev = 0; prev < index; prev++) { // Changed '=' to '<' to iterate till index-1
            if (arr[prev] < arr[index] && 1 + dp[prev] > dp[index]) {
                dp[index] = 1 + dp[prev];
                hash[index] = prev;
            }
        }
        if (dp[index] > maxi) {
            maxi = dp[index];
            lastIndex = index;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());

    return temp; // Returning the longest increasing subsequence instead of its length
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends