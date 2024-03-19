class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++)
        {
            vector<int> sub;
            for(int j=0;j<=i;j++)
            {
                int num;
                if(j == 0 || j == i)
                {
                    num = 1;
                }
                else
                {
                    int row = i-1; 
                    num = ans[row][j] + ans[row][j-1]; 
                }
                sub.push_back(num);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};