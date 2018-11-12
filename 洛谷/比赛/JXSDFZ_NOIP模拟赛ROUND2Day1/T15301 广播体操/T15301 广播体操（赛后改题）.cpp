#include<cstdio>
#include<iostream>
#include<algorithm> 
using namespace std;
typedef long long int ll;
const int MAXN=50001;
ll A[MAXN];
inline ll search_ans(int Left,int Right)
{
	if(Left>Right) return 0;
    else if(Left==Right) return A[Left];
    ll lmax=0,rmax=0,max1,max2,midmax=0,tempans=0;
    int mid=(Left+Right)>>1;
    ll hh;
    max1=search_ans(Left,mid);
    max2=search_ans(mid+1,Right);
    hh=A[Left];
    for(int i=Left;i<=Right;++i)
    {
        if(A[i]>=hh) tempans+=hh;
        else
        {
            lmax=max(lmax,tempans);
            hh=A[i];
            tempans=hh*(i-Left+1);
        }
    }
    lmax=max(lmax,tempans);
	tempans=0;hh=A[Right];
    for(int i=Right;i>=Left;--i)
    {
        if(A[i]>=hh) tempans+=hh;
        else
        {
            rmax=max(rmax,tempans);
            hh=A[i];
            tempans=hh*(Right-i+1);
        }
    }
    rmax=max(rmax,tempans);
	hh=A[mid];tempans=0;
    for(int i=mid;i>=Left;--i)
    {
        if(A[i]>=hh) tempans+=hh;
        else
        {
            for(int j=mid+1;j<=Right;++j)
            {
                if(A[j]>=hh) tempans+=hh;
                else break;
            }
            hh=A[i];
            midmax=max(midmax,tempans);
            tempans=hh*(mid-i+1);
        }
    }
    midmax=max(midmax,tempans);
    hh=A[mid+1];tempans=0;
    for(int i=mid+1;i<=Right;++i)
    {
        if(A[i]>=hh) tempans+=hh;
        else
        {
            for(int j=mid;j>=Left;--j)
            {
                if(A[j]>=hh) tempans+=hh;
                else break;
            }
            hh=A[i];
            midmax=max(midmax,tempans);
            tempans=hh*(i-mid);
    }
        }
    midmax=max(midmax,tempans);
    return max(midmax,max(max(lmax,rmax),max(max1,max2)));
}
inline ll read()
{
    ll x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
    return x;
}
int main()
{
    //freopen("liuce.in","r",stdin);
    //freopen("liuce.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;++i)
        A[i]=read();
    ll ans=search_ans(1,n);
    printf("%lld",ans);
    //fclose(stdin);fclose(stdout);
    return 0;
}
