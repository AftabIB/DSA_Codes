//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
#include<stack>
class Solution
{
    public:
    string reverseWord(string str)
    {
        stack<char> s;
        for(int i=0;i<str.length();i++)
        {
            char ch = str[i];
            s.push(ch);
        }
        
        string ans = "";
        while(!s.empty())
        {
            char ch = s.top();
            ans.push_back(ch);
            s.pop();
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends