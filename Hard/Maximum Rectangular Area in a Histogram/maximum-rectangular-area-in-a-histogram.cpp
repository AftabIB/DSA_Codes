//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
private:
    vector<int> nextSmallerElement(long long arr[], int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }

            ans[i] = st.top();
            // returning in the form of indexes
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(long long arr[], int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {  // Fix the loop condition
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }

            ans[i] = st.top();
            // returning in the form of indexes
            st.push(i);
        }
        return ans;
    }

public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n) {
        vector<int> next = nextSmallerElement(arr, n);
        vector<int> prev = prevSmallerElement(arr, n);

        long long int area = LLONG_MIN;  // Initialize with LLONG_MIN
        for (int i = 0; i < n; i++) {
            long long int l = arr[i];

            if (next[i] == -1) {
                next[i] = n;
            }

            long long int b = next[i] - prev[i] - 1;
            long long int NewArea = l * b;
            area = max(area, NewArea);  // Update the maximum area correctly
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