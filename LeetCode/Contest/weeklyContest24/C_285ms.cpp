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
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n=sz(matrix), m =sz(matrix[0]);
        vector<vi> vis;
        queue<pii> q;
        vector<vi>& a=matrix;
        for(int i=0;i<n;i++){
            vi t(m, 0); vis.pb(t);
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    q.push(mp(i, j));
                    vis[i][j]=1;
                }
                else a[i][j]=0x7fffffff;
            }
        }
        
        while(!q.empty()){
            pii u = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int vx = u.x+dx[i];
                int vy = u.y+dy[i];
                if(vx<0 || vx>=n || vy<0 || vy>=m || vis[vx][vy]) continue;
                if(a[vx][vy])a[vx][vy]=min(a[vx][vy], vis[u.x][u.y]);
                vis[vx][vy]=vis[u.x][u.y]+1;
                q.push(mp(vx, vy));
            }
        }
        
        return a;
    }
};
