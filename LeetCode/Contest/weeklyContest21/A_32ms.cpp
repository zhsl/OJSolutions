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

    vector<int> num;
    
    void dfs(TreeNode* u){
        if(u==NULL){
            return;
        }
        num.push_back(u->val);
        dfs(u->left);
        dfs(u->right);
    }

    int getMinimumDifference(TreeNode* root) {
        num.clear();
        dfs(root);
        sort(num.begin(),num.end());
        int ret=num[1]-num[0];
        for(int i=1;i<num.size();i++){
            if(num[i]-num[i-1]<ret){
                ret=num[i]-num[i-1];
            }
        }
        return ret;        
    }
};
