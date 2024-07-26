//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Initialize distances
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == -1 && i != j) {
                    mat[i][j] = INT_MAX; // Represents no edge
                }
                if (i == j) {
                    mat[i][j] = 0; // Self distance is zero
                }
            }
        }
        
        // Floyd-Warshall algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (mat[i][k] < INT_MAX && mat[k][j] < INT_MAX) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }
        
        // Check for negative cycles
        for (int i = 0; i < n; ++i) {
            if (mat[i][i] < 0) {
                // If negative cycle exists, you may want to handle it or mark it
                // For now, we just leave the matrix as is
                // Optionally, set a flag or take other actions
            }
        }
        
        // Replace INF values with -1 to indicate no path
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == INT_MAX) {
                    mat[i][j] = -1;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends