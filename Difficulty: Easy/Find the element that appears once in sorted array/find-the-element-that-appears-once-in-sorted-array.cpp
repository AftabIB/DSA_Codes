//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        if(n == 1)
            return arr[0];
        
        if(arr[0] != arr[1])
            return arr[0];
        
        if(arr[n-1] != arr[n-2])    
            return arr[n-1];
        
        
        int s = 1;
        int e = n - 2;
        
        while(s <= e)
        {
            int mid = s + (e - s)/2;
            //searching the element 
            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1])
                return arr[mid];
            
            //ellimination left half
            if((mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid % 2 == 0 && arr[mid] == arr[mid+1]))
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1; 
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends