#include<stdio.h>
#include<string.h>
const int MAXN=100010,MAX_HA=10000;
int judge();
char map1[MAXN][11],map2[MAXN][11],dic[11];
struct NODE
{
	struct NODE(){next=NULL;num=0;};
	int num;
	NODE *next;
}hash[MAX_HA];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,key,ok,t;
	for(i=0;i<MAXN;i++)
	{
		scanf("%c",&map1[i][0]);
		if(map1[i][0]=='\n')break;
		scanf("%s%s",&(map1[i][1]),map2[i]);

		for(j=0,key=0;map2[i][j]!='\0';j++){
			t=map2[i][j]-'a';
			key+=t*t;
		}

		NODE *p=&hash[key],*q=new NODE;
		for(;p->next!=NULL;p=p->next);
		p->num=i;
		p->next=q;
		q->next=NULL;
		getchar();
	}

	while(~scanf("%s",dic))
	{
		ok=judge();
		printf("%s\n",ok>=0?map1[ok]:"eh");
	}
	return 0;
}

int judge()
{
	int i,key,ok,t;
	for(i=0,key=0;dic[i]!='\0';i++){
		t=dic[i]-'a';
		key+=t*t;
	}
	NODE *p=&hash[key];
	for(;p->next!=NULL;p=p->next){
		ok=strcmp(map2[p->num],dic);
		if(!ok)return p->num;
	}
	return -1;
}