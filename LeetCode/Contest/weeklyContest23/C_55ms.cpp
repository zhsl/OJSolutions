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
    
    int dfs(TreeNode* &p, string s, int b) {
        if(b>=s.length())return b;
        int t=b;
        if(s[t]!='(' && s[t]!=')'){
            p = new TreeNode(0);
            int flag = 1;
            if(s[t]=='-'){
                flag = -1;
                t++;
            }
            while(t<s.length() && s[t]!='(' && s[t]!=')'){
                p->val*=10;
                p->val+= s[t]-'0';
                t++;
            }
            p->val*=flag;
            //printf("%d\n",p->val);
        }
        if(t<s.length() && s[t]=='('){
            t = dfs(p->left, s, t+1);
        }
        if(t<s.length() && s[t]=='('){
            t = dfs(p->right, s, t+1);
        }
        return t+1;
    }

    TreeNode* str2tree(string s) {
        if(s == "") return NULL;
        TreeNode* root;
        dfs(root, s, 0);
        return root;
    }
};
