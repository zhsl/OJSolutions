#include<iostream>
#include<string>
int max(int a,int b);
using namespace std;
const int MAXN=1000;
struct bign{
    int len,s[MAXN],xsd,much_lin;
    bign(){memset(s,0,sizeof(s));len=1;}; 

	/*char* str() const{
		char res[MAXN];
		for(int i=0,k=0;i<len;i++){
			if(xsd&&xsd==i)res[i]=='.',k=1;
			res[i+k]=s[len-i-1]+'0';
		}
		res[i+k]='\0';
		return res;
	}*/
    string str() const{     //重构数组输出
        string res="";
        for(int i=0;i<len;i++){
			if(xsd&&xsd==i)res=(char)('.')+res;
			res=(char)(s[i]+'0')+res;
		}
        if(res=="")res="0";
        return res;
    }
//**************赋值*****************
    bign operator=(const char* num){   //重构赋值
		int i,g,k,lent;
        len=strlen(num);
		xsd=0,much_lin=0;
        for(i=0,g=0,lent=len-1;i<len;i++){
			if(num[lent-i]!='.')    //去小数点
				s[i-g]=num[lent-i]-'0';
			else xsd=i,g=1;
		}
		if(xsd)len--;
		if(xsd&&s[0]==0){       //处理后置零
			for(i=0;i<xsd&&s[i]==0;i++);
			for(k=i;i<len;i++)
				s[i-k]=s[i];
			len-=k,xsd-=k;
		}
        return *this;   //返回当前这个类
    }
//*********高精度比较大小_小于**********
	bool operator<(const bign& b)const{
		int i,lent=len-xsd;
	    if(len-xsd!=b.len-b.xsd)return len-xsd<b.len-b.xsd;  //整数部分比较 
		for(i=lent;i>=0;i--)
			if(s[i+xsd]!=b.s[i+b.xsd])return s[i+xsd]<b.s[i+b.xsd];                     
		for(i=1,lent=xsd<b.xsd?xsd:b.xsd;i<=lent;i++)                                  //小数部分比较
			if(s[xsd-i]!=b.s[b.xsd-i])return s[xsd-i]<b.s[b.xsd-i];
		if(xsd==b.xsd)return 0;
		else return xsd<b.xsd;
		return false;
	}
//***********高精度加法***************暂无错误
    bign operator+(const bign& b) const{
        bign c;
		int max_len,i,g,cha,k;
		if(xsd<b.xsd){                 //分情况相加
			for(i=0,cha=b.xsd-xsd;i<len;i++)
				c.s[i+cha]=s[i];
			max_len=max(b.len,i+cha),i=0;
			for(g=0;g||i<max_len;i++){
				c.s[i]+=b.s[i];
				g=c.s[i]/10;
				c.s[i]%=10;
			}
			c.len=i;
		}
		else if(b.xsd<xsd){
			for(i=0,cha=xsd-b.xsd;i<b.len;i++)
				c.s[i+cha]=b.s[i];
			max_len=max(len,i+cha),i=0;
			for(g=0;g||i<max_len;i++){
				c.s[i]+=s[i];
				g=c.s[i]/10;
				c.s[i]%=10;
			}
			c.len=i;
		}
		else {
			max_len=max(len,b.len);
			for(i=0,g=0;g||i<max_len;i++){
				c.s[i]=s[i]+b.s[i]+g;
				g=c.s[i]/10;
				c.s[i]%=10;
			}
			c.len=i;
		}
		c.xsd=max(xsd,b.xsd);
		if(c.xsd&&c.s[0]==0){            //处理后置零
			for(i=0;i<c.xsd&&c.s[i]==0;i++);
			for(k=i;i<c.len;i++)
				c.s[i-k]=c.s[i];
			c.len-=k,c.xsd-=k;
		}
        return c;
    }
//************高精度减法**************暂无错误
	bign operator-(const bign& b) const{
		int t[MAXN]={0},i,g,cha,k;
		bign c;
		if(xsd<b.xsd){
			for(i=0,cha=b.xsd-xsd;i<len;i++)
				t[i+cha]=s[i];
			i=0,g=0;
			for(c.len=len+cha;i<c.len;i++){
				c.s[i]=t[i]-b.s[i]+10-g;
				g=c.s[i]<10?1:0;
				c.s[i]%=10;
			}
			cout<<g<<endl;
			if(g)c.len--,c.s[i-1]=0;
		}
		else {
			for(i=0,cha=xsd-b.xsd;i<b.len;i++)
				t[i+cha]=b.s[i];
			i=0,g=0;
			for(c.len=len+cha;i<c.len;i++){
				c.s[i]=s[i]-t[i]+10-g;
				g=c.s[i]<10?1:0;
				c.s[i]%=10;		
			}
			if(g)c.len--,c.s[i-1]=0;
		}
		c.xsd=max(xsd,b.xsd);
		if(c.xsd&&c.s[0]==0){          //处理后置零
			for(i=0;i<c.xsd&&c.s[i]==0;i++);
			for(k=i;i<c.len;i++)
				c.s[i-k]=c.s[i];
			c.len-=k,c.xsd-=k;
		}
		if(!c.s[c.len-1]&&c.len>c.xsd+1)          //处理前置零
			for(;c.s[c.len-1]==0&&c.len>c.xsd+1;c.len--);
		return c;
	}
//************高精度乘法**************
	bign operator*(const bign& b) const{
		bign c;
		int i,j,g,k;
		for(i=0;i<len;i++)
			for(j=0,g=0;g||j<b.len;j++){
				c.s[i+j]=s[i]*b.s[j]+c.s[i+j]+g;
				g=c.s[i+j]/10;
				c.s[i+j]%=10;
			}
		c.len=i+j-1,c.xsd=xsd+b.xsd;
		if(c.xsd&&c.s[0]==0){          //处理后置零
			for(i=0;i<c.xsd&&c.s[i]==0;i++);
			for(k=i;i<c.len;i++)
				c.s[i-k]=c.s[i];
			c.len-=k,c.xsd-=k;
		}
		if(!c.s[c.len-1]&&c.len>c.xsd+1)          //处理前置零
			for(;c.s[c.len-1]==0&&c.len>c.xsd+1;c.len--);
		return c;
	}
/***********高精度除法***************
	bign operator/(const bign& b) const{

	}*/
};
//***********重定义输入输出***********
istream& operator>>(istream &in,bign& x){
    string s;
    in>>s;
    x=s.c_str();
    return in;
}
ostream& operator<<(ostream &out,const bign& x){
    out<<x.str();
    return out;
}
//************************************
int main()
{
//	freopen("in.in","r",stdin);
	bign x,y;
	char r[10];
	int n;
	while(cin>>r>>n)
	{
		x=r,y=r;
		while(--n)
		{
			x=x*y;
		}
		if(x.len==x.xsd+1&&x.s[x.len-1]==0&&x.len>1){
			x.len--;
			cout<<'.';
		}
		cout<<x<<endl;
	}
    return 0;
}

int max(int a,int b)
{
    return a>b?a:b;
}
