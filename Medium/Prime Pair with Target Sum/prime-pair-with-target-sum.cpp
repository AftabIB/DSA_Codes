//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    void getPrime(int n,vector<int>& prime){
        vector<bool> isPrime(n+1,true);
        for(int p=2;p*p<=n;p++){
            if(isPrime[p]){
                for(int i=p*p;i<=n;i+=p){
                    isPrime[i]=false;
                }
            }
        }
        for(int p=2;p<=n;p++){
            if(isPrime[p]){
                prime.push_back(p);
            }
        }
    }

    vector<int> getPrimes(int n) {
        if(n<=3){
            return {-1,-1};
        }
        vector<int> prime;
        getPrime(n,prime);
        vector<vector<int>> p;
        for(int i=0,j=prime.size()-1;i<=j;){
            if(prime[i]+prime[j]==n){
                vector<int> pt;
                pt.push_back(prime[i]);
                pt.push_back(prime[j]);
                p.push_back(pt);
                i++;
                j--;
            }
            else if(prime[i]+prime[j]<n){
                i++;
            } else {
                j--;
            }
        }

        if(p.size()>=1){
            return p[0];
        } else {
            return {-1,-1};
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends