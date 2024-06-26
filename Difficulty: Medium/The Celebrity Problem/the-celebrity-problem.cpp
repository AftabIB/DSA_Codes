//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool knows(vector<vector<int> >& M,int a, int b)
    {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // step 1 : push all the elements into stack
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        
        //step 2 : pop 2 elements and check whether they know to each other
        while(st.size() > 1)
        {
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            // if a know b then a is not a celebrity
            if(knows(M,a,b))
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        
        int candidate = st.top();
        
        for(int i=0;i<n;i++)
        {
            if(M[candidate][i] != 0 && i != candidate)
            {
                return -1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(M[i][candidate] != 1 && i != candidate)
            {
                return -1;
            }
        }
        
        
        // verify that potential candidate satisfies all the conditions
        // row check
        // bool rowCheck = false;
        // int zeroCount = 0;
        
        // for(int i=0;i<n;i++)
        // {
        //     if(M[candidate][i] == 0)
        //     {
        //         zeroCount++;
        //     }
        // }
        
        // if(zeroCount == n)
        // {
        //     rowCheck = true;
        // }
        
        // // col check
        // bool colCheck = false;
        // int oneCount = 0;
        
        // for(int i=0;i<n;i++)
        // {
        //     if(M[i][candidate] == 1)
        //     {
        //         oneCount++;
        //     }
        // }
        
        // if(oneCount == n-1)
        // {
        //     colCheck = true;
        // }
        
        // if both row check and col check is true
        // if(rowCheck == true && colCheck == true)
        // {
        //     return candidate;
        // }
        // else
        // {
        //     return -1;
        // }
        return candidate;
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