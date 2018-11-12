#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=2e5+1;
ll ans=0;
int n,m,k,now=1;
int arr[MAXN],remainder[MAXN];
struct node{
	int val;
	node *nex,*rev;
	node() {val=0;nex=rev=NULL;}
}*num[MAXN];
inline void ins(int key,int kk){
	node *p=new(node);
	p->val=key;num[kk]->rev=p;
	p->nex=num[kk];p->rev=NULL;
	num[kk]=p;
}
inline void del(node *key,int kk){
	//cout<<"hahaha";
	//cout<<"hahaha";
	num[kk]=key->nex;
	num[kk]->rev=NULL;
	delete num[kk]->rev;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();k=n/m;
	for(int i=0;i<m;++i){
		num[i]=new(node);
		num[i]->nex=NULL;num[i]->rev=NULL;
	}
	for(int i=1;i<=n;++i){
		int temp=(arr[i]=read())%m;
		++remainder[temp];
		ins(i,temp);
	}
	//cout<<"fuck"<<endl;
	for(int i=0;i<m-1;++i){
		if(remainder[i]>k){
			while(remainder[now]>=k) now=(now==m-1)?0:(now+1);
			for(node *p=num[i];p&&remainder[i]>k;p=p->nex){
				int temp=(now>i)?(now-i):(now+m-i);
				arr[p->val]+=temp;ans+=temp;
				ins(p->val,now);del(p,i);
				--remainder[i];++remainder[now];
				if(remainder[now]==k) now=(now==m-1)?0:(now+1);
			}
		}
	} 
	if(remainder[m-1]>k){
		while(remainder[now]>=k) now=(now==m-1)?0:(now+1);
		for(node *p=num[m-1];p&&remainder[m-1]>k;p=p->nex){
			int temp=now+1;
			arr[p->val]+=temp;ans+=temp;
			ins(p->val,now);del(p,m-1);
			--remainder[m-1];++remainder[now];
			if(remainder[now]==k) now=(now==m-1)?0:(now+1);
		}
	}
	now=1;
	for(int i=0;i<m-1;++i){
		if(remainder[i]>k){
			while(remainder[now]>=k) now=(now==m-1)?0:(now+1);
			for(node *p=num[i];p&&remainder[i]>k;p=p->nex){
				int temp=(now>i)?(now-i):(now+m-i);
				arr[p->val]+=temp;ans+=temp;
				ins(p->val,now);del(p,i);
				--remainder[i];++remainder[now];
				if(remainder[now]==k) now=(now==m-1)?0:(now+1);
			}
		}
	} 
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i) printf("%d ",arr[i]);
	return 0;
}
