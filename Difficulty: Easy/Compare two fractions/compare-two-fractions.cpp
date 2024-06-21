//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     public:
    string compareFrac(string s) {

        // Code here
        float a,b,c,d;

        string _a, _b, _c, _d;
    
        int i = 0, j = 0;
    
        while(s[i] != '/')  i++;
        _a = s.substr(0, i);
    
        j = i+1;
        
        while(s[i] != ',')  i++;
        _b = s.substr(j, i-j);
    
        j = i+2;
    
        while(s[i] != '/')  i++;
        _c = s.substr(j, i-j);
    
        j = i+1;
    
        while(s[i] != '\0') i++;
        _d = s.substr(j, i-j);
    
        a = stof(_a);
        b = stof(_b);
        c = stof(_c);
        d = stof(_d);
    
        if(a/b == c/d)  return "equal";
        if(a/b > c/d)   return _a+"/"+_b;
    
        return _c+"/"+_d;
   
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends