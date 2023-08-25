//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    int left = 0, right = S.length()-1;
        while(left<right)
        {   
            if(!isalnum(S[left])) 
                left++;
            else if(!isalnum(S[right])) 
                right--;
            else if(tolower(S[left])!=tolower(S[right])) 
                return false;
            else {
                left++; 
                right--;
            }
        }
        return true;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends