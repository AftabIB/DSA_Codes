//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int substrCount (string s, int k) {
    	return atmost(s,k)-atmost(s,k-1);
    }
    
    long long int atmost(string s,int k)
    {
        int arr[26] = {0};
        int left = 0, dist = 0;
        long res = 0;
        
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-'a']++;
            if(arr[s[i]-'a']==1)
            {
                dist++;
            }
            while(dist>k)
            {
                arr[s[left]-'a']--;
                if(arr[s[left]-'a']==0)
                {
                    dist--;
                }
                left++;
            }
            res += (i-left+1);
        }
        return res;
    }
    
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends