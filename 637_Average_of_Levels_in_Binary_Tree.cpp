/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//This method perform dfs
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
//This method perform bfs
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        //This code perform bfs
        queue<TreeNode*> q;
        vector<double> mean;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            for (int i = size;i>0;--i){
                sum+=(q.front())->val;
                if(q.front()->left) q.push((q.front())->left);
                if(q.front()->right) q.push((q.front())->right);
                q.pop();
            }
            mean.push_back(static_cast<double>(sum)/size);
        }

        return mean;
    }


};
