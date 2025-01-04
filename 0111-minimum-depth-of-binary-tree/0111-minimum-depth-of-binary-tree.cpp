class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int count=q.size();
            while(count!=0)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(!curr->left&&!curr->right)
                 return level+1;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                --count;
            }
            ++level;
        }
        return 0;
    }
        
};