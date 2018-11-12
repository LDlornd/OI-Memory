#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=202;
int n,nowred,nowblue,ans=0;
int flag[MAXN];
bool vis[MAXN];
struct edge{
	int v;
	edge *Next;
	edge() {v=0;Next=NULL;}
}*con[MAXN];
struct point{
	int x,y;
}Point[MAXN];
inline void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->Next=con[Start];
	con[Start]=p;
}
inline bool Find(int nv){
    for(edge *p=con[nv];p;p=p->Next){
        int vv=p->v;
        if(vis[vv]==false){
            vis[vv]=true;
            if(flag[vv]==0||Find(flag[vv])){
                flag[vv]=nv;
                return true;
            }
        }
    }
    return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=2*n;++i) cin>>Point[i].x>>Point[i].y;
	for(int i=1;i<=n;++i)
		for(int j=n+1;j<=n*2;++j)
			if(Point[j].x>Point[i].x&&Point[j].y>Point[i].y) ins(i,j);
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof(vis));
		if(Find(i)) ++ans;
	}
	cout<<ans;
	return 0; 
}
