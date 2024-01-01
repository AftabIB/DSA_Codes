//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        sort(greed.begin(),greed.end());
        sort(sz.begin(),sz.end());
        
        int curr = 0;
        int total = 0;
        
        for(int i = 0;i<N;i++)
        {
            while(curr < M && sz[curr] < greed[i])
            {
                curr++;
            }
            
            if(curr < M)
            {
                curr++;
                total++;
            }
            else
            {
                break;
            }
        }
        return total;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends