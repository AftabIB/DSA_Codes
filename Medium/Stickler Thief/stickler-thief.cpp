//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
      if(n==1){
            return arr[0];
        }
        else if(n==2)
        return max(arr[0],arr[1]);
        int a = arr[0], b = max(arr[0],arr[1]),c;
        for(int i=2;i<n;i++){
         c = max(b,a+arr[i]);//c=(7,11)
         a=b,b=c;//a=7 , b =11
        }
        return max(a,b);

       
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends