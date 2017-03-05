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

    int val, cnt, max_cnt;
    vector<int> ret;

    int dfs(TreeNode* root){
        if(root==NULL) return 1;
        dfs(root->left);
        if(cnt==-1){
            val=root->val;
            cnt=1;
        }
        else if(root->val!=val){
            if(cnt>max_cnt){
                max_cnt=cnt;
                ret.clear();
                ret.push_back(val);
            }
            else if(cnt==max_cnt){
                ret.push_back(val);
            }
            val=root->val;
            cnt=1;
        }
        else cnt++;
        dfs(root->right);
        return 1;
    }

    vector<int> findMode(TreeNode* root) {
        cnt=-1, max_cnt=0;
        ret.clear();
        dfs(root);
        if(cnt>max_cnt){
            max_cnt=cnt;
            ret.clear();
            ret.push_back(val);
        }
        else if(cnt==max_cnt){
            ret.push_back(val);
        }
        return ret;
    }
};