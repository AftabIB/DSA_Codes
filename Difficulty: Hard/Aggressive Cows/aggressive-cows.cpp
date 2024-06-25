//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool canBePlace(vector<int> &stalls, int k, int n, int distance)
    {
        int cnt = 1;
        int last = stalls[0];
        for(int i=1;i<n;i++)
        {
            if(stalls[i] - last >= distance)
            {
                cnt++;
                last = stalls[i];
            }
            
            if(cnt >= k)
                return true;
        }
        return false; 
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low = 0;
        int high = stalls[n-1] - stalls[0];
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            bool bePlaced = canBePlace(stalls,k,n,mid);
            if(bePlaced == true)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1; 
            }
        }
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends