//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n){
        // Your code here
        //edge cases
        if(n==0) return 0;
        
        // when n is odd
        if(n%2!=0) return 1;
        
        // when n is power of 2
        if(n!=0 && (n&(n-1))==0) return log2(n)+1;
        
        // when n is even
        int c=1;
        int temp=n;
        while(true){
            c++;
            int d=(temp>>1)&1;
            temp=temp>>1;
            if(d==1) return c;
        }
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends