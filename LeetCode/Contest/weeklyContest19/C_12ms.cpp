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
    vector<int> ret;
public:
    void find(TreeNode* root, int d){
        if(root==NULL)return;
        if(d>=ret.size()){
            ret.push_back(root->val);
        }
        else if(ret[d]<root->val){
            ret[d]=root->val;
        }
        if(root->left!=NULL){
            find(root->left, d+1);
        }
        if(root->right!=NULL){
            find(root->right, d+1);
        }
    }

    vector<int> findValueMostElement(TreeNode* root) {
        ret.clear();
        find(root, 0);
        return ret;
    }
};
