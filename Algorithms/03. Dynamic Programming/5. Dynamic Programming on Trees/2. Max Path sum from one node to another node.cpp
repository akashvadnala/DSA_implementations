class Solution {
public:
    int getans(TreeNode* root,int& ans){
        if(!root) return 0;
        int l=max(0,getans(root->left,ans));
        int r=max(0,getans(root->right,ans));
        ans=max(ans,l+r+root->val);
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        getans(root,ans);
        return ans;
    }
};