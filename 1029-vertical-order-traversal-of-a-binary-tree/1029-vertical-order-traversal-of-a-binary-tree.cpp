class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)return ans;
        
        queue<pair<TreeNode *, pair<int,int>>>q;
        int vertical = 0, level = 0;
        
        //vertical - level - values
        map<int,map<int,multiset<int>>>m;

        q.push({root, {level, vertical}});
        
        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                auto temp = q.front();
                q.pop();
                TreeNode* node = temp.first;


                m[temp.second.second][temp.second.first].insert(node->val);
                if(node->left){
                    q.push({node->left, {temp.second.first + 1, temp.second.second - 1}});
                }
                if(node->right){
                    q.push({node->right, {temp.second.first + 1, temp.second.second + 1}});
                }
            }
        }

        for(auto it : m){
            vector<int>ver;
            for(auto at : it.second){//traversing through second map; 
              for(auto pt : at.second){//traversing through set;
               ver.push_back(pt);
              }
            }
            ans.push_back(ver);
        }
        return ans;
    }
};