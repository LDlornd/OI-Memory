#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=25000;
char s[MAXN][9],prim[MAXN],gs=0;
inline bool judge(int x)
{
    if(s[x][1]=='1'&&s[x][2]=='0'&&s[x][3]=='1') return true;
    if(s[x][1]=='1'&&s[x][2]=='1'&&s[x][3]=='1') return true;
    if(s[x][1]=='0') {prim[++gs]=x;return true;}
    return false;
}
inline void print1(int x)
{
    int ans=0;
    for(int i=8;i>3;--i)
        ans+=(s[x][i]-'0')*pow(2,8-i);
    printf("%c",'A'+ans);
}
inline void print2(int x)
{
    int ans1=0,ans2=0;
    for(int i=8;i>=1;--i)
    {
        ans1+=(s[x][i]-'0')*pow(2,8-i);
        ans2+=(s[x+1][i]-'0')*pow(2,8-i);
    }
    printf("%d",ans1/2+ans2/2);
}
int main()
{
    //freopen("testdata.in","r",stdin);
    //freopen("ans.out","w",stdout);
    memset(prim,0,sizeof(prim));
    bool flag=true;
    int num=0,tot=1;
    char c=getchar();
    while(c!=EOF)
    {
        if(c=='\n'||c==EOF) break;
        s[tot][++num]=c;
        if(num==8)
        {
            if(judge(tot)==false) {flag=false;}
            num=0;++tot;
        }
        c=getchar();
    }
    if(num!=0||flag==false||gs&1) {printf("Error");return 0;}
    for(int i=1;i<=gs;i+=2)
        if(prim[i]+1!=prim[i+1]) {printf("Error");return 0;}
    for(int i=1;i<tot;++i)
    {
        if(s[i][1]=='1'&&s[i][2]=='0'&&s[i][3]=='1') print1(i);
        if(s[i][1]=='1'&&s[i][2]=='1'&&s[i][3]=='1') printf(" ");
        if(s[i][1]=='0') {print2(i);++i;}
    }
    return 0;
}
