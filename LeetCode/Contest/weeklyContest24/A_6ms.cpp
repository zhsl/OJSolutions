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

    int ans;    
    
    int dfs(TreeNode* root){
        if(!root)return 0;
        if(!root->left && !root->right) return 1;
        int dl=0, dr=0;
        if(root->left) dl = dfs(root->left);
        if(root->right) dr = dfs(root->right);
        ans=max(ans,dl+dr);
        return max(dl, dr)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};
