#include<stdio.h>
#include<string.h>
#define LL long long
#define pii pair<int,int>
const int MAX=35,INF=1000000010,MOD=7;
char map[10][10],s[MAX];
char look[2][MAX]={{'K','Q','R','B','N','P'},{'k','q','r','b','n','p'}};
int y[10]={2,6,10,14,18,22,26,30},
x[10]={1,3,5,7,9,11,13,15};
int n=8,m=8;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,ki,kj,flag;
	while(~scanf("%s",s))
	{
		for(i=1,ki=0;i<=16;i++){
			scanf("%s",s);
			if(i==x[ki]){	
				for(j=kj=0;j<=32;j++){
					if(j==y[kj]){
						map[ki][kj]=s[j];
						kj++;
					}
				}
				ki++;
			}	
		}

		printf("White: ");
		flag=0;
		for(k=0;k<6;k++){
			for(i=n-1;i>=0;i--){
				for(j=0;j<m;j++){
					if(map[i][j]==look[0][k]){
						if(flag)printf(",");
						if(k!=5)printf("%c",look[0][k]);
						printf("%c%d",'a'+j,n-i);
						flag=1;
					}
				}
			}
		}

		putchar('\n');
		printf("Black: ");
		flag=0;
		for(k=0;k<6;k++){
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if(map[i][j]==look[1][k]){
						if(flag)printf(",");
						if(k!=5)printf("%c",look[0][k]);
						printf("%c%d",'a'+j,n-i);
						flag=1;
					}
				}
			}
		}
		putchar('\n');
	}
	return 0;
}