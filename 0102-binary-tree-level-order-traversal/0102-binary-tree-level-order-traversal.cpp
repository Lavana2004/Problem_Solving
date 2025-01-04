class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>res;
        q.push(root);
        if(root==NULL) return res;
        while(!q.empty())
        {
            vector<int>v;
            int count=q.size();
            while(count!=0)
            {
                TreeNode* curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                --count;
            }
            res.push_back(v);
        }
        return res;
    }
};