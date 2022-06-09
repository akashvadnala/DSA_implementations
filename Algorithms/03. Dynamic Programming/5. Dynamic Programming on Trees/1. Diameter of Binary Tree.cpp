class Solution {
public:
    int diameter=0;
    int height(TreeNode* root){
        if(!root) return 0;
        int l=height(root->left);
        int r=height(root->right);
        diameter=max(diameter,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};