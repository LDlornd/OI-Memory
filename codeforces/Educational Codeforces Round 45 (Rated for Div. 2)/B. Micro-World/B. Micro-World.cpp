#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200001;
int n,k,lastsize,temp,ans=1;
int arr[MAXN];
struct node{
	int key,num;
	node *nex,*rev;
}*head,*tail;
inline void ins(int Key){
	if(tail->rev->key==Key){
		++tail->rev->num;
		++head->key;
		return;
	}
	node *p=new(node);
	p->key=Key;p->num=1;
	p->nex=tail;p->rev=tail->rev;
	tail->rev->nex=p;tail->rev=p;
	++head->key;
}
inline void del(node *a){
	a->rev->nex=a->nex;
	a->nex->rev=a->rev;
	head->key-=a->num;
}
inline bool CMP(int a,int b){
	return a<b;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();k=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	sort(arr+1,arr+n+1,CMP);
	head=new(node);tail=new(node);
	head->nex=tail;head->rev=NULL;
	tail->rev=head;tail->nex=NULL;
	head->key=0;
	for(int i=1;i<=n;++i){
		ins(arr[i]);
		for(node *p=tail->rev->rev;p!=head;p=p->rev){
			int nk=p->key;
			if(arr[i]>nk&&arr[i]<=nk+k){
				p=p->nex;del(p->rev);continue;
			}
			break;
		}
	}
	printf("%d",head->key);
	return 0;
}
