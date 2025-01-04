class Solution {
    int dia;
public:
    int getWidth(TreeNode* root){
        if(root==nullptr) return 0;
        int lw=getWidth(root->left);
        int rw=getWidth(root->right);
        dia=max(dia, lw+rw);
        return max(lw, rw)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia=0;
        getWidth(root);
        return dia;
    }
};