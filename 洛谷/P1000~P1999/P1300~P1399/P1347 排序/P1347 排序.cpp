#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=30;
char s[4];
int n,m,temp;
int indu[MAXN],copyindu[MAXN];
int Queue[MAXN],head,tail;
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End){
	//cout<<Start<<" "<<End<<endl;
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
	++indu[End];
}
void read(){
	char c=getchar();
	while(c<'A'||c>'Z') c=getchar();
	s[1]=c;s[2]=getchar();s[3]=getchar();
}
int top_sort(){
	int ans=0;
	head=1;tail=0;
	for(int i=0;i<n;++i)
		if((copyindu[i]=indu[i])==0){
			Queue[++tail]=i;
			//cout<<Queue[tail];
		}
	//cout<<tail<<"fuck"<<endl;
	if(tail>1) ans=2;
	while(head-1!=tail){
		int nv=Queue[head++],cnt=0;
		for(edge *p=con[nv];p;p=p->nex)
			if(--copyindu[p->v]==0) {Queue[++tail]=p->v;++cnt;}
		if(cnt>1) ans=2;
	}
	//cout<<"tail=="<<tail<<endl;
	if(tail!=n) ans=0;
	if(tail==n&&ans!=2) ans=1;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		//scanf("%s",s+1);
		read();
		//cout<<s[1]<<" "<<s[3]<<endl;
		ins((s[1]-'A'),(s[3]-'A'));
		temp=top_sort();
		if(temp==0){
			printf("Inconsistency found after %d relations.",i);
			return 0;
		}
		if(temp==1){
			printf("Sorted sequence determined after %d relations: ",i);
			for(int j=1;j<=n;++j)
				printf("%c",'A'+Queue[j]);
			printf(".");
			return 0;
		}
	}
	printf("Sorted sequence cannot be determined.");
	return 0;
}
