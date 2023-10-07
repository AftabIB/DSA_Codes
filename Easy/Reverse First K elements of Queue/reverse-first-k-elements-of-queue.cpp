//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    
    //fetch first k elements from queue and put it into the stack
    stack<int> st;
    for(int i=0;i<k;i++)
    {
        int element = q.front();
        q.pop();
        st.push(element);
    }
    
    //fetch elements from sack and put it into queue
    while(!st.empty())
    {
        int element = st.top();
        st.pop();
        q.push(element);
    }
    
    //fetch first n-k elements from the queue and push_back
    int t = q.size()-k;
    while(t--)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }
    return q;
}