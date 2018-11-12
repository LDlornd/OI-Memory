#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1e5+5;
int T,lens,lent;
char res[MAXN],opt[MAXN];
struct node{
	char color;
	node *nex,*rev;
}*head,*tail;
void ins(char key){
	node *p=new(node);
	p->color=key;
	tail->rev->nex=p;
	p->rev=tail->rev;
	tail->rev=p;
	p->nex=tail;
}
void del(node *key){
	key->nex->rev=key->rev;
	key->rev->nex=key->nex;
}
void init(){
	head=new(node);tail=new(node);
	head->nex=tail;head->rev=NULL;
	tail->rev=head;tail->nex=NULL;
	head->color='W';tail->color='W';
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%s%s",res+1,opt+1);
		lens=strlen(res+1);lent=strlen(opt+1);
		for(int i=1;i<=lens;++i){
			if(res[i]!=res[i-1]){
				ins(res[i]);
			}
		}
		for(int i=1;i<=lent;++i) opt[i]=(opt[i]=='F')?'R':'B';
		for(int i=lent;i>=1;--i){
			bool flag=false;
			for(node *p=head->nex;p!=tail;p=p->nex){
				if(opt[i]==p->color&&p->rev!=head&&p->nex!=tail){
					del(p->nex);del(p);
					flag=true;
					break;
				}
			}
			if(flag==false){
				if(head->nex->color==opt[i]) del(head->nex);
				else if(tail->rev->color==opt[i]) del(tail->rev);
			}
		}
		if(head->nex==tail) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
