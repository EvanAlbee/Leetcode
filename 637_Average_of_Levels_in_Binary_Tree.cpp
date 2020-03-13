/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<long long,int>> cal_sum ;
        vector<double> ans ;
        int depth = 0 ;
        dfs(cal_sum,root,depth);;
        for (vector<pair<long long,int>> :: const_iterator itr=cal_sum.begin();itr!=cal_sum.end();++itr)
            ans.push_back(static_cast<double>(itr->first)/itr->second);        
        return ans;   
        
    }
private: 
    void dfs(vector<pair<long long,int>> &cal_sum,TreeNode* root,int depth){
        if (!root) return ; 
        if (depth>=cal_sum.size()) cal_sum.push_back({0,0});
        cal_sum[depth].first+=root->val;
        ++cal_sum[depth].second;
        ++depth;
        dfs(cal_sum,root->left,depth);
        dfs(cal_sum,root->right,depth);
        
    }
};
