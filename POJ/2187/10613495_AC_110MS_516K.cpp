#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LL __int64
const int MAX=50010;
int cmp(const void *a,const void *b);
int graham();
int nod[MAX][2],stack[MAX][2];
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
            scanf("%d%d",&nod[i][0],&nod[i][1]);
            if(nod[i][1]<y0)x0=nod[i][0],y0=nod[i][1];
			else if(nod[i][1]==y0 && nod[i][0]<x0)x0=nod[i][0],y0=nod[i][1];
        }
        if(n>=3){
			qsort(nod,n,sizeof(int)*2,cmp);		
			graham();

        
			for(i=0;i<top;i++){
				for(j=i+1;j<=top;j++){
					t=(stack[i][0]-stack[j][0])*(stack[i][0]-stack[j][0])+
						(stack[i][1]-stack[j][1])*(stack[i][1]-stack[j][1]);
					if(t>ans)ans=t;
				}
			}
		}
		else ans=(nod[0][0]-nod[1][0])*(nod[0][0]-nod[1][0])
			+(nod[0][1]-nod[1][1])*(nod[0][1]-nod[1][1]);
        
        printf("%d\n",ans);
    }
	return 0;
}

int graham()
{
    int i,x1,y1,x2,y2;
    top=1;
    stack[0][0]=nod[0][0],stack[0][1]=nod[0][1];
    stack[1][0]=nod[1][0],stack[1][1]=nod[1][1];
    for(i=2;i<n;i++){
        while(top>=1){
            x1=nod[i][0]-stack[top][0],y1=nod[i][1]-stack[top][1];
            x2=stack[top-1][0]-stack[top][0],y2=stack[top-1][1]-stack[top][1];
            if((x1*y2-x2*y1)>0)break;
            else top--;
        }
        stack[++top][0]=nod[i][0];
        stack[top][1]=nod[i][1];
    }
    return 1;
}

int cmp(const void *a,const void *b)
{
    int t,x1=*(int*)a,y1=*((int*)a+1),
        x2=*(int*)b,y2=*((int*)b+1);
    x1-=x0,y1-=y0;
    x2-=x0,y2-=y0;
	t=x1*y2-x2*y1;
    if(t)return -t;
	return (x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)-(x2-x0)*(x2-x0)-(y2-y0)*(y2-y0);
}