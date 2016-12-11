#include<stdio.h>
#include<string.h>
const int N=12,MOD=100000000;
int map[N][N],f[2][(1<<N)+10],n,m;
int main()
{
    int i,j,k,p,ans;
    while(~scanf("%d%d",&n,&m)){
        ans=0;memset(f,0,sizeof(f));f[0][0]=p=1;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&map[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++,memset(f[p=!p],0,sizeof(f[0])))
                for(k=0;k<(1<<m);k++)
                    if(k&(1<<j))
                        f[p][k&~(1<<j)]=(f[p][k&~(1<<j)]+f[!p][k])%MOD;
                    else {
                        f[p][k]=(f[p][k]+f[!p][k])%MOD;
                        if((j && !(k&(1<<(j-1))) || !j ) && map[i][j])
                            f[p][k|(1<<j)]=(f[p][k|(1<<j)]+f[!p][k])%MOD;
                    }
        for(i=0,p=!p;i<(1<<m);i++)ans=(ans+f[p][i])%MOD;
        printf("%d\n",ans);
    }
    return 0;
}