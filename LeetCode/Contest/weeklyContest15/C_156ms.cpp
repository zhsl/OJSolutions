class Solution {
public:
    int vis[6];
    int hlen;
    const int INF = 100;

    string get_new(string board, int w, char tar){
        string ret = board.substr(0, w) + tar + board.substr(w, board.length() - w);
        int l=w,r=w, l_t, r_t;
        int cnt=-1;
        while(l>=0 && r<ret.length() && ret[l]==ret[r]) {
            l_t = l, r_t = r;
            char t = ret[l];
            while(l>=0 && ret[l]==t) l--,cnt++;
            while(r<ret.length() && ret[r]==t)r++,cnt++;
            if(cnt<3) {
                l=l_t, r=r_t;
                break;
            }
            cnt = 0;
        }
        if(l==w)l--;
        string ans = ret.substr(0, l+1) + (r==ret.length()?"":ret.substr(r, ret.length()-r));
        return ans;
    }

    int dfs(string board, string hand, int vis[], int cnt, int d) {
        if(board.length() == 0) {
            return d;
        }
        if(cnt==0) return -1;
        int ret = INF;
        for(int i=0;i<hlen;i++){
            if(vis[i]==1)continue;
            vis[i]=1;
            cnt--;
            for(int j=0;j<=board.length();j++){
                int flag = 0;
                if(j-1>=0 && board[j]==hand[i])flag=1;
                if(j<=board.length() && board[j]==hand[i])flag=1;
                if(!flag)continue;
                string new_board = get_new(board, j, hand[i]);
                int t = dfs(new_board, hand, vis, cnt, d+1);
                if(t < ret && t != -1) ret = t;
            }
            vis[i]=0;
            cnt++;
        }
        return ret==INF?-1:ret;
    }

    int findMinStep(string board, string hand) {
        hlen = hand.length();
        for(int i=0;i<hlen;i++)vis[i]=0;
        return dfs(board, hand, vis, hlen, 0);
    }
};
