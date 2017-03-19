#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define inf 1000000007
#define mod 1000000007
#define x first
#define y second
#define pi acos(-1.0)
#define ull unsigned long long
#define ll long long
#define N 200010

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

    vi v, pre;

    void dfs(TreeNode* root){
        if(!root)return;
        v.pb(root->val);
        dfs(root->left);
        dfs(root->right);
        return;
    }

    void dfs2(TreeNode* root){
        if(!root)return;
        int w = upper_bound(v.begin()+1, v.end(), root->val) - v.begin()-1;
        //printf("%d %d %d %d\n", root->val, pre[sz(v)-1], pre[w-1], w);
        root->val+=pre[sz(v)-1] - pre[w];
        dfs2(root->left);
        dfs2(root->right);
        return;
    }

    TreeNode* convertBST(TreeNode* root) {
        v.clear(); pre.clear();
        v.pb(0); pre.pb(v[0]);
        dfs(root);
        sort(v.begin()+1, v.end());
        for(int i=1;i<sz(v);i++){
            pre.pb(pre[i-1] + v[i]);
        }
        dfs2(root);
        return root;
    }
};




