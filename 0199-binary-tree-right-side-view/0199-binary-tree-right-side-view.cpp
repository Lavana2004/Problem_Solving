class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL) return ans;
        while(!q.empty())
        {
            vector<int>v;
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr!=NULL){
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                }
            }
            res.push_back(v);
        }
        for(int i=0;i<res.size();i++)
        {
            ans.push_back(res[i][res[i].size()-1]);
        }
        return ans;
    }
};
   