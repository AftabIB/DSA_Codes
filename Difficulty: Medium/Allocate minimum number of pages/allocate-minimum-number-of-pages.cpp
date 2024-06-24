//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
  
    int solve(int arr[],int n,int pages)
    {
        int studs = 1;
        long long studPages = 0;
        for(int i=0;i<n;i++)
        {
            if(studPages + arr[i] <= pages)
            {
                studPages += arr[i];
            }
            else
            {
                studs++;
                studPages = arr[i];
            }
        }
        return studs;
    }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        
        if(m > n)
            return -1;
        
        int low = *max_element(arr,arr+n);
        int high = accumulate(arr,arr+n,0);     //does summation of all the elements
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int reqStud = solve(arr,n,mid);
            if(reqStud > m)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends