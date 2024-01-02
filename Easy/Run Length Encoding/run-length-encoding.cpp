//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  int n = src.length();
  string str = "";
  int count = 1;
  
  for(int i=0;i<=n-2;i++)
  {
      if(src[i] == src[i+1])
      {
          count += 1;
      }
      else
      {
          str += src[i];
          str += to_string(count);
          count = 1;
      }
  }
  
  str += src[n-1];
  return str+to_string(count);
}     
 
