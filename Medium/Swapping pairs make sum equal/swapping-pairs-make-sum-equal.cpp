//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int sum(int a[],int n)
  {
      int summ=0;
      for(int i=0;i<n;i++)
      summ=summ+a[i];
      return summ;
  }
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int sa=sum(a,n);
        int sb=sum(b,m);
        int k=abs(sa-sb);
        unordered_set<int> arr;
        for(int i=0;i<m;i++)
        arr.insert(b[i]);
        if(k%2!=0)
        return -1;
        k=k/2;
        for(int i=0;i<n;i++)
        {
            if(sa>sb)
            {
                if(arr.find(a[i]-k)!=arr.end())
                return 1;
            }
            if(sa<=sb)
            {
                if(arr.find(a[i]+k)!=arr.end())
                return 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends