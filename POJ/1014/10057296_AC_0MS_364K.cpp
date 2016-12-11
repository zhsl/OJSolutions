#include<stdio.h>
int DFS(int s,int p);
int n[7],tar;
int main()
{
//	freopen("in.txt","r",stdin);
	int k=1,ok,i;
	while(scanf("%d%d%d%d%d%d",&n[1],&n[2],&n[3],&n[4],&n[5],&n[6])
		&& n[1]+n[2]+n[3]+n[4]+n[5]+n[6] )
	{
		for(i=1,tar=0;i<=6;i++)tar+=i*n[i];
		if(tar&1)ok=0;
		else tar/=2,ok=1;
		if(ok)ok=DFS(0,6);
		printf("Collection #%d:\n",k++);
		printf("%s\n\n",ok?"Can be divided.":"Can't be divided.");
	}
	return 0;
}

int DFS(int s,int p)
{
	if(s==tar)return 1;
	for(int i=p;i>0;i--){
		if(n[i] && s+i<=tar){
			n[i]--;
			if(DFS(s+i,i))return 1;
		}
	}
	return 0;
}