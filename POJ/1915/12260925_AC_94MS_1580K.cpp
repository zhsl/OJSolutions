#include<stdio.h>
#include<string.h>
int sx,sy,ex,ey;
int dir[8][2]={2,1,2,-1,-2,1,-2,-1,-1,2,-1,-2,1,2,1,-2};
struct node
{
    int x,y,step;
}knight[90010];
int visit[305][305];
int bfs(int n)
{
    int front=0,rear=1,tx,ty,c=0;
    knight[0].x=sx;
    knight[0].y=sy;
    knight[0].step=0;
    memset(visit,0,sizeof(visit));
    node cur,change;
    while(rear>front)
    {
       cur=knight[front++];
       if(cur.x==ex&&cur.y==ey)
       return cur.step;
       else
       {
          for(int i=0;i<8;i++)
          {
              tx=cur.x+dir[i][0];
              ty=cur.y+dir[i][1];
              if(tx>=0&&tx<n&&ty>=0&&ty<n&&visit[tx][ty]==0)
              {
                 visit[tx][ty]=1;
                 change.x=tx;
                 change.y=ty;
                 change.step=cur.step+1;
                 knight[rear++]=change;
              }
          }
       }
    }
}
int main()
{
    int cas,n;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        scanf("%d%d",&sx,&sy);
        scanf("%d%d",&ex,&ey);
        printf("%d\n",bfs(n));
    }
    return 0;
}
