#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int INF=2147483647;
const int MAXN=405;
int casenum,s,t,A,B,T;
double dist[MAXN],ans;
int Queue[MAXN],head,tail;
bool flag[MAXN];
struct point{
	double x,y;
	point() {x=y=0;}
}arr[MAXN];
struct edge{
	int v;
	double val;
	edge *nex;
	edge() {v=val=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End,double key){
	//cout<<Start<<" "<<End<<" "<<key<<endl;
	edge *p=new(edge);
	p->v=End;p->val=key;
	p->nex=con[Start];con[Start]=p;
}
bool judge(int key){
	double temp1=0,temp2=0;
	temp1+=(arr[(key<<2)+1].x-arr[(key<<2)+2].x)*(arr[(key<<2)+1].x-arr[(key<<2)+2].x);
	temp1+=(arr[(key<<2)+1].y-arr[(key<<2)+2].y)*(arr[(key<<2)+1].y-arr[(key<<2)+2].y);
	temp1+=(arr[(key<<2)+1].x-arr[(key<<2)+3].x)*(arr[(key<<2)+1].x-arr[(key<<2)+3].x);
	temp1+=(arr[(key<<2)+1].y-arr[(key<<2)+3].y)*(arr[(key<<2)+1].y-arr[(key<<2)+3].y);
	temp2+=(arr[(key<<2)+3].x-arr[(key<<2)+2].x)*(arr[(key<<2)+3].x-arr[(key<<2)+2].x);
	temp2+=(arr[(key<<2)+3].y-arr[(key<<2)+2].y)*(arr[(key<<2)+3].y-arr[(key<<2)+2].y);
	return temp1==temp2;
}
void get_the_last_point(int key){
	if(judge(key)){
		arr[(key<<2)+4].x=arr[(key<<2)+2].x+arr[(key<<2)+3].x-arr[(key<<2)+1].x;
		arr[(key<<2)+4].y=arr[(key<<2)+2].y+arr[(key<<2)+3].y-arr[(key<<2)+1].y;
		return;
	}
	swap(arr[(key<<2)+1],arr[(key<<2)+2]);
	if(judge(key)){
		arr[(key<<2)+4].x=arr[(key<<2)+2].x+arr[(key<<2)+3].x-arr[(key<<2)+1].x;
		arr[(key<<2)+4].y=arr[(key<<2)+2].y+arr[(key<<2)+3].y-arr[(key<<2)+1].y;
		return;
	}
	swap(arr[(key<<2)+1],arr[(key<<2)+3]);
	arr[(key<<2)+4].x=arr[(key<<2)+2].x+arr[(key<<2)+3].x-arr[(key<<2)+1].x;
	arr[(key<<2)+4].y=arr[(key<<2)+2].y+arr[(key<<2)+3].y-arr[(key<<2)+1].y;
}
double getdist(int Start,int End){
	double ans=0;
	ans+=(arr[Start].x-arr[End].x)*(arr[Start].x-arr[End].x);
	ans+=(arr[Start].y-arr[End].y)*(arr[Start].y-arr[End].y);
	return sqrt(ans);
}
void spfa(int Start){
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=(s<<2);++i) dist[i]=INF;
	dist[Start]=0;flag[Start]=true;
	Queue[head=tail=1]=Start;
	while(head-1!=tail%(MAXN-1)){
		int nv=Queue[head];
		for(edge *p=con[nv];p;p=p->nex){
			//cout<<p->v<<" "<<dist[p->v]<<" "<<dist[nv]+p->val<<"fuck"<<endl;
			if(dist[p->v]>dist[nv]+p->val){
				dist[p->v]=dist[nv]+p->val;
				//cout<<p->v<<" "<<dist[p->v]<<"fuck"<<endl;
				if(flag[p->v]==false){
					tail=(tail==MAXN-1)?1:(tail+1);
					Queue[tail]=p->v;
					flag[p->v]=true;
				}
			}
		}
		head=(head==MAXN-1)?1:(head+1);
		flag[nv]=false;
	}
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	casenum=read();
	while(casenum--){
		memset(con,0,sizeof(con));
		s=read();t=read();
		A=read()-1;B=read()-1;
		for(int i=0;i<s;++i){
			for(int j=1;j<=3;++j)
				scanf("%lf%lf",&arr[(i<<2)+j].x,&arr[(i<<2)+j].y);
			T=read();
			get_the_last_point(i);
			for(int j=1;j<=4;++j)
				for(int w=1;w<=4;++w)
					if(j!=w) ins((i<<2)+j,(i<<2)+w,getdist((i<<2)+j,(i<<2)+w)*T);
		}
		for(int i=0;i<s;++i)
			for(int j=0;j<s;++j){
				if(i==j) continue;
				for(int k=1;k<=4;++k)
					for(int w=1;w<=4;++w)
						ins((i<<2)+k,(j<<2)+w,getdist((i<<2)+k,(j<<2)+w)*t);
			}
		ans=INF;
		//cout<<ans<<endl;
		for(int i=1;i<=4;++i){
			spfa((A<<2)+i);
			//cout<<dist[(B<<2)+1]<<" "<<dist[(B<<2)+2]<<" "<<dist[(B<<2)+3]<<" "<<dist[(B<<2)+4]<<" ";
			ans=min(ans,min(min(dist[(B<<2)+1],dist[(B<<2)+2]),min(dist[(B<<2)+3],dist[(B<<2)+4])));
			//cout<<ans<<endl;
		}
		printf("%.1lf\n",ans);
	}
	return 0;
}
