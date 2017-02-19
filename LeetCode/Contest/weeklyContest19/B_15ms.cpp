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
    int max_depth;
    int ret;
public:
    void find(TreeNode* root, int depth) {
        if(root->left==NULL && root->right==NULL){
            if(depth>max_depth){
                max_depth=depth;
                ret=root->val;
                return;
            }
        }
        if(root->left!=NULL){
            find(root->left, depth+1);
        }
        if(root->right!=NULL){
            find(root->right, depth+1);
        }
    }
    
    int findLeftMostNode(TreeNode* root) {
        max_depth=-1;
        find(root, 0);
        return ret;
    }
};
