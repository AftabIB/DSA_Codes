class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        
        int row = 0,col = 0;

        bool isReverse = false;

        while(col < n) // Corrected loop condition
        {
            int i = row, j = col;
            vector<int> temp;
            //push elements 
            while(i<m && j<n && i>=0 && j>=0)
            {
                temp.push_back(mat[i][j]);
                i--;
                j++;
            }

            if(isReverse)
                reverse(temp.begin(),temp.end());
            

            ans.insert(ans.end(),temp.begin(),temp.end());

            if(row != m-1)
            {
                row++;
                col = 0;
            }
            else
            {
                col++;
            }
            isReverse = !isReverse;
        }
        return ans;

    }
};
