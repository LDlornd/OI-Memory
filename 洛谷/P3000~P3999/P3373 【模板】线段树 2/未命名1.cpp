                        #include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=100010;
int n,m,mod,a[maxn];
int read()
{
    char ch=getchar();
    int f=1,x=0;
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
    
}
struct tree
{
    tree *ls,*rs;
    int l,r;
    ll sum,add,mul;
    tree()
    {
        ls=rs=NULL;
        add=0;mul=1;
    }
    void update()
    {
        sum=(ls->sum+rs->sum)%mod;
    }
    void cal(ll ca,ll cm)
    {
        mul=mul*cm%mod;
        add=add*cm%mod;
        add=(add+ca)%mod;
        sum=(sum*cm%mod+ca*(r-l+1)%mod)%mod;
    }
    void pushdown()
    {
        rs->cal(add,mul);ls->cal(add,mul);
        add=0;mul=1;
    }
    void build(int lx,int rx)
    {
        l=lx;r=rx;
        if(l==r) {sum=a[l];return ;}
        int mid=(l+r)>>1;
        (ls=new tree)->build(lx,mid);
        (rs=new tree)->build(mid+1,rx);
        update();
    }
    void modify(int lx,int rx,int ca,int cm)
    {
        //cout<<"modify:"<<l<<' '<<r<<' '<<lx<<' '<<rx<<endl;
        if(l==lx&&r==rx) {cal(ca,cm);return;}
        pushdown();
        
        //cout<<"!!!"<<endl;
        int mid=(l+r)>>1;
        if(rx<=mid) ls->modify(lx,rx,ca,cm);
        else if(lx>mid) rs->modify(lx,rx,ca,cm);
        else ls->modify(lx,mid,ca,cm),rs->modify(mid+1,rx,ca,cm);
        update();		
    }
    int query(int lx,int rx)
    {
        if(l==lx&&r==rx) {return sum;}
        pushdown();
        int mid=(l+r)>>1;
        if(rx<=mid) return ls->query(lx,rx);
        else if(lx>mid) return rs->query(lx,rx);
        else return (ls->query(lx,mid)+rs->query(mid+1,rx))%mod;
        update();
    }
}*xtr;
int main()
{
    n=read();m=read();mod=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    (xtr=new tree)->build(1,n);
    for(int i=1;i<=m;i++)
    {
        //cout<<"!!!!!"<<endl;
        int opt=read(),l=read(),r=read();
        ll k;
        if(opt==1) k=read(),xtr->modify(l,r,0,k);
        if(opt==2) k=read(),xtr->modify(l,r,k,1);
        if(opt==3) printf("%d\n",xtr->query(l,r));
        //xtr->outp();
        //cout<<endl;
    }	
    return 0;
}
                    

