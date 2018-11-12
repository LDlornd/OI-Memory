#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=200001;
char opt,s[10];
int q,tot=0;
ll mod,nownum,ans=0;
ll num[MAXN],val[MAXN];
inline void modify(int place,int k)
{
    num[place]=k;
    for(;place<MAXN;place+=(place&-place))
    {
        val[place]=k;
        for(int i=1;i<(place&-place);i<<=1)
            val[place]=max(val[place],val[place-i]);
    }
}
inline ll query(int start,int end)
{
    ll tempans=0;
    while(end>=start)
    {
        tempans=max(tempans,num[end]);
        --end;
        for(;end-(end&-end)>=start;end-=(end&-end))
            tempans=max(tempans,val[end]);
    }
    return tempans;
}
int main()
{
    scanf("%d%lld\n",&q,&mod);
    memset(val,0,sizeof(val));
    while(q--)
    {
        scanf("%s",s);scanf("%lld",&nownum);
        int len=strlen(s);
        for(int i=0;i<len;++i)
            if(s[i]=='A'||s[i]=='Q') {opt=s[i];break;}
        if(opt=='A') modify(++tot,(nownum+ans)%mod);
        else
        {
            if(nownum==0||tot==0) printf("%lld\n",ans=0);
            else printf("%lld\n",ans=query(tot-nownum+1,tot));
        }
    }
    return 0;
}
