#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
string s;
int n,ans=0;
set<string> st;
int main(){
	scanf("%d",&n);
	while(n--){
		cin>>s;
		st.insert(s);
	}
	set<string>::iterator it;
	for(it=st.begin();it!=st.end();++it) ++ans;
	printf("%d",ans);
	return 0;
}
