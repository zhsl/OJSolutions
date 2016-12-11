#include<stdio.h>
#include<memory.h>
int DFS(int x,int y,int cur);
int is_uni(int x,int y,int a);
void in_uni(int x,int y,int a);
void out_uni(int x,int y,int a);
const int MAXN=10;
char map[MAXN][MAXN];
int vis_x[MAXN][MAXN],vis_y[MAXN][MAXN],vis_xy[MAXN][MAXN];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,n,tot,t;
	scanf("%d",&n);

	while(n--)
	{
		tot=0;
		memset(vis_x,0,sizeof(vis_x));
		memset(vis_y,0,sizeof(vis_y));
		memset(vis_xy,0,sizeof(vis_xy));

		for(i=0;i<9;i++){
			scanf("%s",map[i]);
			for(j=0;j<9;j++)
				if(map[i][j]!='0'){
					tot++;
					t=map[i][j]-'1';
					vis_x[i][t]=1;
					vis_y[j][t]=1;
					in_uni(i,j,t);
				}
		}	
//test
		printf("x:\n");
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				printf("%2d",vis_x[i][j]);
			putchar('\n');
			}
		putchar('\n');
//
//test
		printf("y:\n");
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				printf("%2d",vis_y[i][j] );
			putchar('\n');
			}
		putchar('\n');
//
//test
		printf("xy:\n");
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				printf("%2d",vis_xy[i][j] );
			putchar('\n');
			}
		putchar('\n');
//

		DFS(0,0,tot);

		for(i=0;i<9;i++)
			printf("%s\n",map[i]);
	}
	return 0;
}

int DFS(int x,int y,int cur)
{
/*test
		printf("x:\n");
		for(int i=0;i<9;i++){
			for(int k=0;k<9;k++)
				printf("%2d",vis_x[i][k] );
			putchar('\n');
			}
		putchar('\n');
*/
	if(cur==81)return 1;  //search succeed
	if(x==8&&y==8)return 0;
	for(int j=0;j<=8;j++)
	{
		if(map[x][y]=='0'){
	    	if( !vis_x[x][j] && (!(vis_y[y][j])) && is_uni(x,y,j) ){
				map[x][y]=j+'1';
		    	vis_x[x][j]=1;
		    	vis_y[y][j]=1;
		    	in_uni(x,y,j);
				if(DFS(y<8?x:x+1,y<8?y+1:0,cur+1))return 1;
		    	vis_x[x][j]=0;
		    	vis_y[y][j]=0;
	 	    	out_uni(x,y,j);
				map[x][y]='0';
			}
		}
		else {
			if(DFS(y<8?x:x+1,y<8?y+1:0,cur))return 1;
		}
	}
	return 0;
}

int is_uni(int x,int y,int a)
{
	if(x<=2){
		if(y<=2){if( vis_xy[0][a] )return 0;else return 1;}
		else if(y<=5){if( vis_xy[1][a] )return 0;else return 1;}
		else {if( vis_xy[2][a] )return 0;else return 1;}
	}
	else if(x<=5){
		if(y<=2){if( vis_xy[3][a] )return 0;else return 1;}
		else if(y<=5){if( vis_xy[4][a] )return 0;else return 1;}
		else{if( vis_xy[5][a] )return 0;else return 1;}
	}
	else {
		if(y<=2){if( vis_xy[6][a] )return 0;else return 1;}
		else if(y<=5){if( vis_xy[7][a] )return 0;else return 1;}
		else{if( vis_xy[8][a] )return 0;else return 1;}
	}
}

void in_uni(int x,int y,int a)
{
	if(x<=2){
		if(y<=2)vis_xy[0][a]=1;
		else if(y<=5)vis_xy[1][a]=1;
		else vis_xy[2][a]=1;
	}
	else if(x<=5){
		if(y<=2)vis_xy[3][a]=1;
		else if(y<=5)vis_xy[4][a]=1;
		else vis_xy[5][a]=1;
	}
	else {
		if(y<=2)vis_xy[6][a]=1;
		else if(y<=5)vis_xy[7][a]=1;
		else vis_xy[8][a]=1;
	}
}

void out_uni(int x,int y,int a)
{
	if(x<=2){
    	if(y<=2)vis_xy[0][a]=0;
    	else if(y<=5)vis_xy[1][a]=0;
    	else vis_xy[2][a]=0;
	}
	else if(x<=5){
		if(y<=2)vis_xy[3][a]=0;
		else if(y<=5)vis_xy[4][a]=0;
		else vis_xy[5][a]=0;
	}
	else {
		if(y<=2)vis_xy[6][a]=0;
		else if(y<=5)vis_xy[7][a]=0;
		else vis_xy[8][a]=0;
	}
}