//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int getPivot(vector<int>& arr, int key)
    {
        int start = 0;
        int end = arr.size()-1;
        
        while(start < end)
        {
            int mid = start + (end - start)/2;
            
            if(arr[mid] >= arr[0])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
            mid = start + (end - start)/2;
        }
        return start;
    }
    
    int BS(vector<int> &arr, int s, int e, int key)
    {
        int start = s;
        int end = e;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(arr[mid] == key)
                return mid;
            
            else if( key > arr[mid])
                start = mid + 1;
            
            else
                end = mid - 1;
            
            mid = start + (end - start)/2;
        }
        return -1;
    }
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size();
        int pivot = getPivot(arr,key);
        
        if(key >= arr[pivot] && key <= arr[n-1])
        {
            return BS(arr,pivot,n-1,key);
        }
        else
        {
            return BS(arr,0,pivot - 1,key);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends