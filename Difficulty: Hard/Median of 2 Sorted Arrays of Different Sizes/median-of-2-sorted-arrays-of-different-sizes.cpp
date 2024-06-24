//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++


// brute force

    // double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    // {
    //     // Your code goes here
    //     vector<int> arr;
    //     int n1 = array1.size(), n2 = array2.size();
    //     int i = 0, j = 0;
        
    //     while(i < n1 && j < n2)
    //     {
    //         if(array1[i] < array2[j])
    //         {
    //             arr.push_back(array1[i]);
    //             i++;
    //         }
    //         else
    //         {
    //             arr.push_back(array2[j]);
    //             j++;
    //         }
    //     }
        
    //     while(i < n1)
    //     {
    //         arr.push_back(array1[i]);  
    //         i++;
    //     }
        
    //     while(j < n2)
    //     {
    //         arr.push_back(array2[j]);  
    //         j++;
    //     }
        
    //     int n = (n1 + n2);
        
    //     if(n%2 == 1)
    //     {
    //         return arr[n/2];
    //     }
        
    //     return (double)((double)(arr[n/2]) + (double)(arr[n/2 - 1])) / 2.0;
    // }
    

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n1 = array1.size();
        int n2 = array2.size();
        
        int i = 0, j = 0;
        
        int n = (n1 + n2);
        int ind2 = n/2;
        int ind1 = ind2 - 1;
        
        int indEle1 = -1, indEle2 = -1; 
        int cnt = 0;
        
        while(i < n1 && j < n2)
        {
            if(array1[i] < array2[j])
            {
                if(cnt == ind1)
                    indEle1 = array1[i];
                    
                if(cnt == ind2)
                    indEle2 = array1[i];
                    
                cnt++;
                i++;
            }
            else
            {
                if(cnt == ind1)
                    indEle1 = array2[j];
                    
                if(cnt == ind2)
                    indEle2 = array2[j];
                    
                cnt++;
                j++;
            }
        }
        
        while(i < n1)
        {
            if(cnt == ind1)
                    indEle1 = array1[i];
                    
            if(cnt == ind2)
                indEle2 = array1[i];
                    
            cnt++;
            i++;
        }
        
        while(j < n2)
        {
            if(cnt == ind1)
                indEle1 = array2[j];
                    
            if(cnt == ind2)
                indEle2 = array2[j];
                    
            cnt++;
            j++;
        }
        
        if(n % 2 == 1)
        {
            return indEle2;
        }
        
        return (double)((double)(indEle1 + indEle2)) / 2.0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends