#include<stdio.h>
#include<string.h>
const int MAX=100010;
char s[MAX],t[MAX];
int main()
{
    int i,j;
    while(~scanf("%s%s",s,t))
    {
        for(i=j=0;t[i]!='\0';i++){
            if(t[i]==s[j])j++;
            if(s[j]=='\0')break;
        }
        printf("%s\n",s[j]=='\0'?"Yes":"No");
    }
    return 0;
}