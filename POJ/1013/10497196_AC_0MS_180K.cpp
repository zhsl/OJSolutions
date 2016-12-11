#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
using namespace std;
int n;
int d[2]={0,2};
char l[3][13],r[3][13],res[3][10],a[13],b[13];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,wl,wr,k,t,p,ok;
	char ans[2][10]={"light","heavy"};
	scanf("%d",&n);
	map<string,int> f;
	f["even"]=1,f["up"]=2,f["down"]=3;
	while(n--)
	{
		for(i=0;i<3;i++)
			scanf("%s%s%s",l[i],r[i],res[i]);
		for(i=0;i<12;i++){
			t='A'+i;
			for(j=0;j<2;j++){
				for(p=0,ok=1;p<3;p++){
					for(k=wl=0;l[p][k]!='\0';k++)
						wl+=l[p][k]==t?d[j]:1;
					for(k=wr=0;r[p][k]!='\0';k++)
						wr+=r[p][k]==t?d[j]:1;
					if(f[res[p]]==1 && wl!=wr){ok=0;break;}
					else if(f[res[p]]==2 && wl<=wr){ok=0;break;}
					else if(f[res[p]]==3 && wl>=wr){ok=0;break;}
					if(!ok)break;
				}
				if(ok)break;
			}
			if(ok)break;
		}
		printf("%c is the counterfeit coin and it is %s.\n",'A'+i,ans[j]);
	}
	return 0;
}