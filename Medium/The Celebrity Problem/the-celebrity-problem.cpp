//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    
    int knows(vector<vector<int> >& M, int a, int b,int n)
    {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // step 1 : push all the elements in stack
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        
        // step 2 : get 2 elements from stack (a,b) and compare both of them, if a knows b, discard a and push b or vice versa 
        
        while(s.size() > 1)
        {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        
        // step 3 : store the potential candidate, which will be top of stack 
        
        int ans = s.top();
        
        /* step 4 : verify, if all the row are zero , then rowcheck is true and 
                            if all the columns are one except diagonal , then colcheck is true*/
        
        bool rowCheck = false;
        int zeroCount = 0;
        
        //checking all the row elements are zero 
        for(int i=0;i<n;i++)
        {
            if(M[ans][i] == 0)
            {
                zeroCount++;
            }
        }
        
        if(zeroCount == n)
        {
            rowCheck = true;
        }
        
        bool colCheck = false;
        int colCount = 0;
        
        for(int i=0;i<n;i++)
        {
            if(M[i][ans] == 1)        
            {
                colCount++; 
            }
        }
        
        if(colCount == n-1)        //check all the cols are 1 except diagonal
        {
            colCheck = true;
        }
        
        // step 5 : if rowcheck and colcheck is true then return ans else return -1
        
        if(rowCheck == true && colCheck == true)
        {
            return ans;
        }
        else
        {   
            return -1;
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
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends