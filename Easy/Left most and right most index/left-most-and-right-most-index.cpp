//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    int search(vector<long long> v, long long x,bool left)
    {
        int index = -1;
        int start = 0;
        int end = v.size() - 1;
        
        while(end >= start)
        {
            int mid = start + (end - start)/2;
            if(v[mid] == x)
            {
                index = mid;
                if(left)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            
            else if(v[mid] < x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return index;
    }
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        int left = search(v,x,true);
        int right = search(v,x,false);
        
        if(left <= right)
        {
            return {left,right};
        }
        else
        {
            return {-1,-1};
        }
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends