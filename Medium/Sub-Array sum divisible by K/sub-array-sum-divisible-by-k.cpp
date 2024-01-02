//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long subCount(long long arr[], int N, long long K)
	{
	    // Your code goes here
	    vector<int> modCount(K,0);
	    int sum = 0;
	    int count = 0;
	    modCount[0] = 1;
	    
	    for(int i=0;i<N;i++)
	    {
	        sum += arr[i];
	        int mod = (sum % K + K) % K;
	        count += modCount[mod];
	        modCount[mod]++;
	    }
	    return count;
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
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends