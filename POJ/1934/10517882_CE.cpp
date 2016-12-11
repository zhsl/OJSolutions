#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
const int MAX=100,MAXC=1010;
int getl(char *a,int b[][27],int len);
solve(int p1,int p2,int w);
int cmp(const int i,const int j);
char a[MAX],b[MAX],ans[MAXC][100],anst[100];
int dp[MAX][MAX],wh[MAXC],la[MAX][27],lb[MAX][27];
int lena,lenb,k,max;
map<string,int> p;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%s%s",a,b))
	{
		p.clear();
		max=0;
		memset(dp,0,sizeof(dp));
		lena=strlen(a),lenb=strlen(b);

		getl(a,la,lena);
		getl(b,lb,lenb);

		/*
		for(i=1;i<=lena;i++){
			for(j=0;j<26;j++)
				printf("%2d",la[i][j]);
			putchar('\n');
		}
		*/
		for(i=1;i<=lena;i++){
			for(j=1;j<=lenb;j++){
				if(a[i-1]==b[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else if(dp[i-1][j]>dp[i][j-1])
					dp[i][j]=dp[i-1][j];
				else dp[i][j]=dp[i][j-1];
			}
		}
		/*
		for(i=0;i<=lena;i++){
			for(j=0;j<=lenb;j++)
				printf("%2d",dp[i][j]);
			putchar('\n');
		}
		*/

		max=dp[lena][lenb];
		k=0;
		solve(lena-1,lenb-1,max-1);

		sort(wh,wh+k,cmp);	
		for(i=0;i<k;i++)
			printf("%s\n",ans[wh[i]]);
			
	}
	return 0;
}

int getl(char *a,int b[][27],int len)
{
	int i,j,t;
	for(i=0;i<=len;i++)b[0][i]=0;
	for(i=1;i<=len;i++){
		for(j=1;j<=26;j++){
			t=a[i-1]-'a'+1;
			if(j==t)
				b[i][j]=i-1;
			else b[i][j]=b[i-1][j];
		}
	}
	return 1;
}

int solve(int p1,int p2,int w){
	if(p1<0 || p2<0){
		anst[max]='\0';
		strcmp(ans[k++],anst);
		return 1;
	}
	if(a[p1]==b[p2]){
		anst[w]=a[p1];
		solve(p1-1,p2-2,w-1);
	}
	else {
		int i,max=-1,pp1,pp2,maxp1,maxp2;
		for(i=1;i<=26;i++){
			pp1=la[p1+1][i],pp2=lb[p2+1][i];
			if(pp1-1==p1 && pp2-1==p2) continue;
			if(dp[pp1][pp2]>max){
				max=dp[pp1][pp2];
				maxp1=pp1;
				maxp2=pp2;
			}
		}
		for(i=1;i<=26;i++){
			pp1=la[p1+1][i],pp2=lb[p2+1][i];
			if(pp1-1==p1 && pp2-1==p2) continue;
			if(dp[pp1][pp2]==max)
				anst[w-1]=a[p1];
				solve(pp1-1,pp2-1,w-1);
		}
	}
	return 1;
}

int cmp(const int i,const int j)
{
	if(strcmp(ans[i],ans[j])<0)return 1;
	else return 0;
}