#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+1;
int n,range[MAXN];
double need[MAXN],Copy,ans=0;
struct node{
	int nv;
	double have;
	node *nex,*rev;
	node(int vv=0,double hh=0) {nv=vv;have=hh;}
}*head,*tail;
inline void ins(node *a){
	a->nex=tail;a->rev=tail->rev;
	tail->rev->nex=a;tail->rev=a;
}
inline void del(node *a){
	a->rev->nex=a->nex;
	a->nex->rev=a->rev;
}
int main(){
	head=new(node);tail=new(node);
	head->rev=NULL;head->nex=new(node);
	head->nex->rev=head;head->nex->nex=tail;
	tail->rev=head->nex;tail->nex=NULL;
	scanf("%d%lf",&n,&head->nex->have);
	for(int i=1;i<=n;++i){
		scanf("%lf%d",&need[i],&range[i]);
		Copy=need[i];
		//cout<<need[i]<<" "<<range[i]<<endl;
		for(node *p=tail->rev;p!=head;p=p->rev){
			//cout<<p->nv<<" "<<p->have<<" "<<need[i]<<endl;
			if(p->nv>range[i]) continue;
			if(p->have>need[i]*5){
				p->have-=need[i]*5;
				need[i]=0;
				node *v=new(node);
				v->nv=i;v->have=Copy;
				//cout<<v->have<<endl;
				ins(v);
				break;
			}
			else if(p->have==need[i]*5){
				//cout<<"fuck"<<endl;
				need[i]=0;
				node *v=new(node);
				v->nv=i;v->have=Copy;
				ins(v);
				p=p->nex;
				del(p->rev);
				break;
			}
			else{
				need[i]-=p->have/5;
				p=p->nex;
				del(p->rev);
			}
		}
		if(need[i]!=0){
			printf("-1");
			return 0;
		}
	}
	//for(node *p=head->nex;p!=tail;p=p->nex) cout<<p->have<<" ";cout<<endl;
	for(node *p=head;p!=tail;p=p->nex)
		ans+=p->have;
	printf("%.7lf",ans/5);
}
