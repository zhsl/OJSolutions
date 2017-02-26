
static const int dx[8] = {-1, 0, 1, 0 , -1 , -1 , 1 , 1};
static const int dy[8] = {0, 1, 0, -1 , -1 , 1 , -1 , 1};

class Solution {
public:

    vector<vector<char>> ret;
    int vis[60][60];

    int dfs(vector<vector<char>>& board, int x,int y)
    {
        if(vis[x][y])return 0;
        vis[x][y]=1;
        if(board[x][y]=='M')return 1;
        if(board[x][y]!='E')return 1;
        int cnt=0;
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=board.size() || ny<0 || ny>=board[0].size())continue;
            cnt += board[nx][ny]=='M'?1:0;
        }
        if(cnt==0){
            ret[x][y]='B';
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 || nx>=board.size() || ny<0 || ny>=board[0].size())continue;
                dfs(board,nx,ny);
            }
        }
        else {
            ret[x][y]=cnt+'0';
        }
        return 0;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        memset(vis,0,sizeof(vis));
        ret.clear();
        for(int i=0;i<board.size();i++){
            vector<char> t;
            ret.push_back(t);
            for(int j=0;j<board[i].size();j++){
                ret[i].push_back(board[i][j]);
            }
        }
        
        if(ret[click[0]][click[1]]=='M')ret[click[0]][click[1]]='X';
        else dfs(board, click[0],click[1]);
        
        return ret;
    }
};
