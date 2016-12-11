#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LL __int64
const int MAX=50010;
int cmp(const void *a,const void *b);
int graham();
int node[MAX][2],stack[MAX][2];
int n,x0,y0,top;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,ans,t;
	while(~scanf("%d",&n))
	{
        ans=0;
        y0=100010;
        for(i=0;i<n;i++){
            scanf("%d%d",&node[i][0],&node[i][1]);
            if(node[i][1]<y0)x0=node[i][0],y0=node[i][1];
        }
        
        qsort(node,n,sizeof(int)*2,cmp);
        graham();
        
        for(i=0;i<top-1;i++){
            for(j=i+1;j<top;j++){
                t=(stack[i][0]-stack[j][0])*(stack[i][0]-stack[j][0])+
                    (stack[i][1]-stack[j][1])*(stack[i][1]-stack[j][1]);
                if(t>ans)ans=t;
            }
        }
        
        printf("%d\n",ans);
    }
	return 0;
}

int graham()
{
    int i,j,x1,y1,x2,y2;
    top=3;
    stack[0][0]=node[0][0],stack[0][1]=node[0][1];
    stack[1][0]=node[1][0],stack[1][1]=node[1][1];
    stack[2][0]=node[2][0],stack[2][1]=node[2][1];
    for(i=3;i<n;i++){
        while(1){
            x1=node[i][0]-stack[top-1][0],y1=node[i][1]-stack[top-1][1];
            x2=stack[top-2][0]-stack[top-1][0],y2=stack[top-2][1]-stack[top-1][1];
            if(x1*y2-x2*y1)break;
            else top--;
        }
        stack[top][0]=node[i][0];
        stack[top++][1]=node[i][1];
    }
    return 1;
}

int cmp(const void *a,const void *b)
{
    int x1=*(int*)a,y1=*((int*)a+1),
        x2=*(int*)b,y2=*((int*)b+1);
    x1-=x0,y1-=y0;
    x2-=x0,y2-=y0;
    return x1*y2-x2*y1;
}