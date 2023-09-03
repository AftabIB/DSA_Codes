class Solution {
public:
// int uniquePaths(int i, int j, int n, int m) {
//     // Check if you've reached the bottom-right cell.
//     if (i == (n - 1) && j == (m - 1)) {
//         return 1;
//     }

//     // Check if you're out of the matrix index.
//     if (i >= n || j >= m) {
//         return 0;
//     }

//     int a = uniquePaths(i + 1, j, n, m);
//     int b = uniquePaths(i, j + 1, n, m);
//     return a + b;
// }

// int uniquePaths(int m, int n) {
//     return uniquePaths(0, 0, m, n);
// }



    int uniquePaths(int m, int n,int i=0, int j=0) {

        // Approach 1 : recursion (brute force)
        // // Base case: If we reach the bottom-right cell, return 1.
        // if (m == 1 && n == 1) {
        //     return 1;
        // }
        
        // // Recursive cases: Move either down or right and count unique paths.
        // int unique_paths = 0;
        
        // // Move down (if there are rows below)
        // if (m > 1) {
        //     unique_paths += uniquePaths(m - 1, n);
        // }
        
        // // Move right (if there are columns to the right)
        // if (n > 1) {
        //     unique_paths += uniquePaths(m, n - 1);
        // }
        
        // return unique_paths;


        // Approach 2 : DP
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the top row and left column to 1, as there's only one way to reach any cell in them.
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        // Fill the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};