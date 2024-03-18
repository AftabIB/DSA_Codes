class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         int n = matrix.size();
        int m = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if the first row needs to be zeroed out
        for(int j = 0; j < m; j++) {
            if(matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if the first column needs to be zeroed out
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Mark zeros on first row and first column
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeros except for first row and first column
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set zeros for the first row if needed
        if(firstRowZero) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Set zeros for the first column if needed
        if(firstColZero) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};


// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         vector<int> row(n);
//         vector<int> col(m);

//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j] == 0)
//                 {
//                     row[i] = 1;
//                     col[j] = 1;
//                 }
//             }
//         }

//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(row[i] == 1 || col[j] == 1)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };