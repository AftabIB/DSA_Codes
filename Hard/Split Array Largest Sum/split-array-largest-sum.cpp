//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int subArray(int arr[], int N, int num)
{
    int sum = 1;
    long long element = 0;
    for(int i = 0; i < N; i++)
    {
        if(element + arr[i] <= num)
        {
            element += arr[i];
        }
        else
        {
            sum += 1;
            element = arr[i];
        }
    }
    return sum;
}

int splitArray(int arr[], int N, int K) 
{
    if(K > N) return -1;
    int low = *max_element(arr, arr + N);
    int high = accumulate(arr, arr + N, 0);
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int element = subArray(arr, N, mid);
        if(element > K)
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends