//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int c=0;
     if(s[0]=='-'){
         c++;
     }
     
     int sum=0;
     
     if(c){
         for(int i=1;i<s.length();i++){
             if(s[i]>=48 && s[i]<=57){
             int r=s[i]-48;
             sum=sum*10+r;
             r=0;
             }
             else
             return -1;
         }
     }


     else{
         for(int i=0;i<s.length();i++){
             if(s[i]>=48 && s[i]<=57){
             int r=s[i]-48;
             sum=sum*10+r;
             r=0;
             }
             else{
                 return -1;
             }
         }
     }


     
     if(c){
         sum=-sum;
         return sum;
     }
     else{
         return sum;
     }
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends