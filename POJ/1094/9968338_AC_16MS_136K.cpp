#include<stdio.h>
#include<string.h>
#define get(u,v) (G[u]&(1<<v))     //位运算处理
#define put(u,v) (G[u]|=(1<<v))
#define out(u,v) (G[u]&=~(1<<v))
const int MAXN=30;
char A[MAXN];
int topo_dfs(int cur);
int is_zero(int v);
int s,n,m,G[MAXN],map[MAXN],tot;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,u,v,ok,result,w;
	char a,b,ch[5];
	while(~scanf("%d%d",&n,&m) && n)
	{
		tot=result=0;         //初始化
		memset(G,0,sizeof(G));
		memset(map,0,sizeof(map));
		getchar();

		for(i=0;i<m;i++){
			scanf("%c<%c\n",&a,&b);
			u=a-'A',v=b-'A';
			if(!get(u,v))put(u,v);       //位运算
			if(!map[u])map[u]=1,tot++;
			if(!map[v])map[v]=1,tot++;
			s=0;
			ok=topo_dfs(0);
			if(ok==-1){result=1;w=i+1;break;}
			else if(s==1){A[n]='\0';result=2;w=i+1;break;}
		}
		for(i++;i<m;i++)
			gets(ch);

		if(result==1)printf("Inconsistency found after %d relations.\n",w);    //按情况输出
		else if(result==2)printf("Sorted sequence determined after %d relations: %s.\n",w,A);
		else printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}

int topo_dfs(int cur)
{
	if(cur==n){s++;return 1;}
	if(s==2)return 2;    //有多个
	else if(cur==tot)return 3; //搜索完成
	int v,ok,t,ans;
	for(ok=0,v=0;v<n;v++){
		if( is_zero(v) && map[v] ){
			ok=1;
			t=G[v];      //位运算很方便的解决了赋值问题
			G[v]=0;
			map[v]=0;
			A[cur]=v+'A';
			ans=topo_dfs(cur+1);
			if(ans==-1)return -1;   //存在回路
			if(ans==2){G[v]=t;map[v]=1;return 2;}   //这里一定要注意剪枝
			if(ans==3){G[v]=t;map[v]=1;return 3;}   //这里一定要注意剪枝
			G[v]=t;
			map[v]=1;
		}
	}
	if(ok)return 0;
	else return -1;    //存在回路
}

int is_zero(int v)      //是否存在回路
{
	for(int i=0;i<n;i++)
		if(get(i,v))return 0;
	return 1;
}