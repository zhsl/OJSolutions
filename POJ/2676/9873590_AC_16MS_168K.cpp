#include<stdio.h>
#include<string.h>

int map[10][10],ar[80][2],used1[10][10],used2[10][10];

int judge(int j,int k,int i)//宫,j/3*3很巧妙啊
{
	int p,q;
	for(p=j/3*3;p<=j/3*3+2;p++)
	{
		for(q=k/3*3;q<=k/3*3+2;q++)
		{
			if(map[p][q]==i)return 0;
		}
	}
	return 1;
}

int dfs(int num)//0的个数
{
	int i,j,k;
	j=ar[num][0],k=ar[num][1];
	if(num<0)return 1;
	for(i=0;i<9;i++)//填数
	{
		if(judge(j,k,i+1)&&!used1[j][i]&&!used2[k][i])//if这后面熟悉不？
		{
			used1[j][i]=used2[k][i]=1;
			map[j][k]=i+1;
			if(dfs(num-1))return 1;
			used1[j][i]=used2[k][i]=0;
			map[j][k]=0;
		}
	}
	return 0;
}

int main()
{
	int i,j,T,num;
	char str[10];
	scanf("%d",&T);
	while(T--)
	{
		memset(used1,0,sizeof(used1));
		memset(used2,0,sizeof(used2));
		num=0;
		for(i=0;i<9;i++)
		{
			scanf("%s",str);
			for(j=0;j<9;j++)
			{
				map[i][j]=str[j]-'0';
				if(!map[i][j])//记录0的位置
				{
					ar[num][0]=i;
					ar[num][1]=j;
					num++;
				}
				if(map[i][j])used1[i][map[i][j]-1]=1;//记录第i行的数
			}
		}
		for(j=0;j<9;j++)
		{
			for(i=0;i<9;i++)
			{
				if(map[i][j])used2[j][map[i][j]-1]=1;//记录第j列的数
			}
		}
		dfs(num-1);
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
				printf("%d",map[i][j]);
			printf("\n");
		}
	}
	return 0;
}