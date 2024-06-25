//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findPivot(vector<int>& arr, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;
    
    while(start <= end)
    {
        if(arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int BS(vector<int>& arr, int s, int e, int t)
{
    int start = s;
    int end = e;
    int mid = start + (end - start)/2;
    
    while(start <= end)
    {
        if(arr[mid] == t)
        {
            return mid;
        }
        else if(t > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

    int search(int n, vector<int>& arr, int key) {
        // Find the pivot point
        int pivot = findPivot(arr, n);
    
        // If pivot is 0, then the array is not rotated
        if (pivot == 0) {
            return BS(arr, 0, n - 1, key);
        }
    
        // If key is greater than or equal to the first element, search in the left sorted portion
        if (key >= arr[0] && key <= arr[pivot - 1]) {
            return BS(arr, 0, pivot - 1, key);
        }
        // Otherwise, search in the right sorted portion
        else {
            return BS(arr, pivot, n - 1, key);
    }
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(n, A, key) << endl;
    }
    return 0;
}
// } Driver Code Ends