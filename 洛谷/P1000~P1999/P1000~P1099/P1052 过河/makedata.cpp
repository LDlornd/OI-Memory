#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100005;
bool flag[MAXN];
int main(){
	freopen("testdata.in","w",stdout);
	srand(time(0));
	int L=rand()%10000+1,S=rand()%10+1,T=rand()%10+1,m=rand()%min(101,L);
	while(L==1) L=rand()%10+1;
	while(T<S) T=rand()%10+1;
	cout<<L<<endl<<S<<" "<<T<<" "<<m<<endl;
	while(m--){
		int k=rand()%L+1;
		while(k==L||flag[k]) k=rand()%L+1;
		flag[k]=true;
		cout<<k<<" ";
	}
	return 0;
}
