#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int m,opt,k;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	scanf("%d",&m);
	while(m--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&k);
			q.push(k);
		}
		if(opt==2) printf("%d\n",q.top());
		if(opt==3) q.pop();
	}
	return 0;
}
