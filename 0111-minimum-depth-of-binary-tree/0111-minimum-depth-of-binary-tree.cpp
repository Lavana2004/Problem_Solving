class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL) return 1+minDepth(root->right);
        if(root->right==NULL)return 1+minDepth(root->left);
        return min(minDepth(root->left)+1,minDepth(root->right)+1);
        
    }
};