#include<stdio.h>
#include<memory.h>
int DFS(int cur);
int is_01(int cur);
const int MAXN=110;
int ok[MAXN],tot[210],a,b[MAXN],d[2]={1,0},bt[210][MAXN];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,max;
	for(a=1;a<=200;a++){
		ok[a]=0;
		memset(b,0,sizeof(b));
		b[0]=1;

		DFS(1);

		for(j=0;j<100;j++)
			bt[a][j]=b[j];
	}

	while(scanf("%d",&a)&&a)
	{
		max=tot[a];
		printf("%d  ",ok[a]);
		for(i=0;i<max;i++)
			printf("%d",bt[a][i]);
		putchar('\n');
	}
	return 0;
}

int DFS(int cur)
{
	if(is_01(cur)){ok[a]=1;tot[a]=cur;return 1;}
	if(cur<100){
    	for(int i=0;i<2;i++)
		{
	     	b[cur]=d[i];
	    	if(DFS(cur+1))return 1;
	    	b[cur]=0;
		}
	}
	return 0;
}

int is_01(int cur)
{
	int i,t;
	for(i=0,t=0;i<cur;i++){
		t=t*10+b[i];
		t%=a;
	}
	if(t)return 0;
	else return 1;
}