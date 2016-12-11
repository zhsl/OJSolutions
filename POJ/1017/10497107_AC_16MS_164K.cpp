#include<stdio.h>
#include<string.h>
const int MAX=100010;
int num[6],ch[6]={36,9,4,1,1,1};
int main()
{
//	freopen("in.txt","r",stdin);
	int ans;
	while(scanf("%d%d%d%d%d%d",&num[0],&num[1],&num[2],&num[3],&num[4],&num[5])
		&& (num[0]||num[1]||num[2]||num[3]||num[4]||num[5])){
		ans=num[5];
		while(num[4])
		{
			ans+=1;
			num[4]--;
			num[0]-=11;
			if(num[0]<0)num[0]=0;
			if(!num[0])break;
		}
		while(num[3]){
			if(num[1]>=5){
				ans+=1;
				num[1]-=5;
				num[3]--;
			}
			else{
				ans+=1;
				num[0]-=20-4*num[1];
				if(num[0]<0)num[0]=0;
				num[1]=0;
				num[3]--;
			}
			if(!num[0] && !num[1])break;
		}
		ans+=num[2]/4;
		num[2]%=4;
		if(num[2]==3){
			if(num[1]>=1){
				num[1]--;
				if(num[1]<0)num[1]=0;
				num[0]-=5;
				if(num[0]<0)num[0]=0;
				ans++;
			}
			else {
				num[0]-=9;
				if(num[0]<0)num[0]=0;
				ans++;
			}
		}
		if(num[2]==2){
			if(num[1]>=3){
				num[1]-=3;
				if(num[1]<0)num[1]=0;
				num[0]-=6;
				if(num[0]<0)num[0]=0;
				ans++;
			}
			else {
				num[0]-=18-num[1]*4;
				if(num[0]<0)num[0]=0;
				num[1]=0;
				ans++;
			}
		}
		if(num[2]==1){
			if(num[1]>=5){
				num[1]-=5;
				if(num[1]<0)num[1]=0;
				num[0]-=7;
				if(num[0]<0)num[0]=0;
				ans++;
			}
			else {
				num[0]-=27-num[1]*4;
				num[1]=0;
				if(num[0]<0)num[0]=0;
				ans++;
			}
		}
		num[2]=0;
		ans+=num[1]/9;
		num[1]%=9;
		if(num[1]){
			num[0]-=36-num[1]*4;
			if(num[0]<0)num[0]=0;
			ans++;
		}
		num[1]=0;
		ans+=num[0]/36;
		num[0]%=36;
		if(num[0])ans++;
		if(num[4])ans+=num[4];
		if(num[3])ans+=num[3];
		printf("%d\n",ans);
	}
	return 0;
}