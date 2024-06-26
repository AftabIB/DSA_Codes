//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<int> nextSmaller(long long arr[], int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmaller(long long arr[], int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
        
    }
    
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int> nextS(n);
        nextS = nextSmaller(arr,n);
        
        
        vector<int> prevS(n);
        prevS = prevSmaller(arr,n);
        
        long long int area = LLONG_MIN;
        for(int i=0;i<n;i++)
        {
            //edge case
            if(nextS[i] == -1)
            {
                nextS[i] = n;
            }
            
            long long int l = arr[i];
            long long int b = nextS[i] - prevS[i] - 1;
            
            long long int newArea = l * b;
            
            area = max(area, newArea);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends