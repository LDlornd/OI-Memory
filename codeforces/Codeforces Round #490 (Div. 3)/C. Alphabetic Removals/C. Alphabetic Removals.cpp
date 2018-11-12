#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
char place;
int n,k,temp=0,remain;
int num[26];
struct node{
	char c;
	node *nex,*rev;
	node() {c=0;nex=rev=NULL;}
}*head,*tail;
inline void ins(char key){
	node *p=new(node);
	p->c=key;
	p->nex=tail;p->rev=tail->rev;
	tail->rev->nex=p;tail->rev=p;
	++num[key-'a'];
}
inline void del(node *key){
	key->nex->rev=key->rev;
	key->rev->nex=key->nex;
}
inline void read(){
	char cc=getchar();
	while(cc<'a'||cc>'z') cc=getchar();
	for(;cc>='a'&&cc<='z';cc=getchar()){
		ins(cc);
	}
}
int main(){
	head=new(node);tail=new(node);
	head->nex=tail;head->rev=NULL;
	tail->nex=NULL;tail->rev=head;
	scanf("%d%d",&n,&k);
	read();
	for(char c='a';c<='z';++c){
		temp+=num[c-'a'];`1
		if(temp>=k) {place=c;remain=num[c-'a']-temp+k;break;}
	}
	for(node *p=head->nex;p!=tail;p=p->nex){
		if(p->c>='a'&&p->c<place){
			p=p->rev;
			del(p->nex);
		}
	}
	for(node *p=head->nex;p!=tail&&remain;p=p->nex){
		if(p->c==place){
			p=p->rev;--remain;
			del(p->nex);
		}
	}
	for(node *p=head->nex;p!=tail;p=p->nex) printf("%c",p->c);
	return 0;
}
