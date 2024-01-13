//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int minManipulation (int n, string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << minManipulation (n, s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minManipulation (int N, string S1, string S2)
{
    int mp_s1[26] = {0};
    int mp_s2[26] = {0};
    
    for(int i=0;i<N;i++)
    {
        mp_s1[S1[i] - 'a']++;
        mp_s2[S2[i] - 'a']++;
    }
    
    int result = 0;
    
    for(int i=0;i<26;i++)
    {
        if(mp_s1[i] > mp_s2[i])
        {
            result += mp_s1[i] - mp_s2[i];
        }
    }
    return result;
}