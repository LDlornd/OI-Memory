#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define Rint register int
#define mem(a,b) memset(a,(b),sizeof(a))
#define Temp template<typename T>
using namespace std;
typedef long long LL;
Temp inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}

#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define len (r-l+1)

const int maxn=200000+10;
int n,m,r,mod;
//������ 
int e,beg[maxn],nex[maxn],to[maxn],w[maxn],wt[maxn];
//��ʽǰ�������飬w[]��wt[]��ʼ��Ȩ���� 
int a[maxn<<2],laz[maxn<<2];
//�߶������顢lazy���� 
int son[maxn],id[maxn],fa[maxn],cnt,dep[maxn],siz[maxn],top[maxn]; 
//son[]�ض��ӱ��,id[]�±��,fa[]���׽ڵ�,cnt dfs_clock/dfs��,dep[]���,siz[]������С,top[]��ǰ�����˽ڵ� 
int res=0;
//��ѯ�� 

inline void add(int x,int y){//��ʽǰ���Ǽӱ� 
    to[++e]=y;
    nex[e]=beg[x];
    beg[x]=e;
}
//-------------------------------------- ����Ϊ�߶��� 
inline void pushdown(int rt,int lenn){
    laz[rt<<1]+=laz[rt];
    laz[rt<<1|1]+=laz[rt];
    a[rt<<1]+=laz[rt]*(lenn-(lenn>>1));
    a[rt<<1|1]+=laz[rt]*(lenn>>1);
    a[rt<<1]%=mod;
    a[rt<<1|1]%=mod;
    laz[rt]=0;
}

inline void build(int rt,int l,int r){
    if(l==r){
        a[rt]=wt[l];
        if(a[rt]>mod)a[rt]%=mod;
        return;
    }
    build(lson);
    build(rson);
    a[rt]=(a[rt<<1]+a[rt<<1|1])%mod;
}

inline void query(int rt,int l,int r,int L,int R){
	//cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    if(L<=l&&r<=R){res+=a[rt];res%=mod;return;}
    else{
        if(laz[rt])pushdown(rt,len);
        if(L<=mid)query(lson,L,R);
        if(R>mid)query(rson,L,R);
    }
}

inline void update(int rt,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){
        laz[rt]+=k;
        a[rt]+=k*len;
    }
    else{
        if(laz[rt])pushdown(rt,len);
        if(L<=mid)update(lson,L,R,k);
        if(R>mid)update(rson,L,R,k);
        a[rt]=(a[rt<<1]+a[rt<<1|1])%mod;
    }
}
//---------------------------------����Ϊ�߶��� 
inline int qRange(int x,int y){
    int ans=0;
    cout<<x<<" "<<y<<endl;
    while(top[x]!=top[y]){//�������㲻��ͬһ������ 
        if(dep[top[x]]<dep[top[y]])swap(x,y);//��x���Ϊ���������˵���ȸ�����Ǹ���
        res=0;
        query(1,1,n,id[top[x]],id[x]);//ans����x�㵽x���������� ��һ������ĵ�Ȩ��
        ans+=res;
        ans%=mod;//������ȡģ 
        x=fa[top[x]];//��x����x���������˵��Ǹ��������һ����
        cout<<x<<" "<<y<<" "<<ans<<endl;
    }
    //ֱ�������㴦��һ������
    if(dep[x]>dep[y])swap(x,y);//��x����ȸ�����Ǹ���
    cout<<x<<" "<<y<<" "<<ans<<endl;
    res=0;
    query(1,1,n,id[x],id[y]);//��ʱ�ټ��ϴ�ʱ�����������ͼ���
    cout<<id[x]<<" "<<id[y]<<" "<<res<<endl;
    ans+=res;
    return ans%mod;
}

inline void updRange(int x,int y,int k){//ͬ�� 
    k%=mod;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        update(1,1,n,id[top[x]],id[x],k);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    update(1,1,n,id[x],id[y],k);
}

inline int qSon(int x){
    res=0;
    query(1,1,n,id[x],id[x]+siz[x]-1);//���������Ҷ˵�Ϊid[x]+siz[x]-1 
    return res;
}

inline void updSon(int x,int k){//ͬ�� 
    update(1,1,n,id[x],id[x]+siz[x]-1,k);
}

inline void dfs1(int x,int f,int deep){//x��ǰ�ڵ㣬f���ף�deep��� 
    dep[x]=deep;//���ÿ�������� 
    fa[x]=f;//���ÿ����ĸ��� 
    siz[x]=1;//���ÿ����Ҷ�ӽڵ��������С 
    int maxson=-1;//��¼�ض��ӵĶ����� 
    for(Rint i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==f)continue;//��Ϊ������continue 
        dfs1(y,x,deep+1);//dfs����� 
        siz[x]+=siz[y];//�����Ķ������ӵ������� 
        if(siz[y]>maxson)son[x]=y,maxson=siz[y];//���ÿ����Ҷ�ӽڵ���ض��ӱ�� 
    }
}

inline void dfs2(int x,int topf){//x��ǰ�ڵ㣬topf��ǰ������˵Ľڵ� 
    id[x]=++cnt;//���ÿ������±�� 
    wt[cnt]=w[x];//��ÿ����ĳ�ʼֵ�����±������ 
    top[x]=topf;//������������Ķ��� 
    if(!son[x])return;//���û�ж����򷵻� 
    dfs2(son[x],topf);//���ȴ����ض��ӣ��ٴ�������ӵ�˳��ݹ鴦�� 
    for(Rint i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==fa[x]||y==son[x])continue;
        dfs2(y,y);//����ÿһ������Ӷ���һ�������Լ���ʼ���� 
    }
}
inline void print(){
	cout<<"*******************"<<endl;
	for(int i=1;i<=n;++i){
		res=0;
		query(1,1,n,id[i],id[i]);
    	cout<<id[i]<<" "<<res<<" "<<fa[i]<<" "<<top[i]<<" "<<son[i]<<" "<<siz[i]<<endl;
	}
	cout<<"*******************"<<endl;
}
int main(){
	freopen("testdata.in","r",stdin);
    read(n);read(m);read(r);read(mod);
    for(Rint i=1;i<=n;i++)read(w[i]);
    for(Rint i=1;i<n;i++){
        int a,b;
        read(a);read(b);
        add(a,b);add(b,a);
    }
    dfs1(r,0,1);
    dfs2(r,r);
    build(1,1,n);
    print();
    while(m--){
        int k,x,y,z;
        read(k);
        if(k==1){
            read(x);read(y);read(z);
            updRange(x,y,z);
        }
        else if(k==2){
            read(x);read(y);
            printf("%d\n",qRange(x,y));
        }
        else if(k==3){
            read(x);read(y);
            updSon(x,y);
        }
        else{
            read(x);
            printf("%d\n",qSon(x));
        }
        print();
    }
}
